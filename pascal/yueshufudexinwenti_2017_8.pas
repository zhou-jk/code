//PrayerOJ 1403
type node=record
            num:integer;
            last,next:^node;
          end;
var
  head,now,t:^node;
  m,n,s,k,i,j:integer;
procedure delete;
begin
  t^.next^.last:=t^.last; t^.last^.next:=t^.next;
  write(t^.num);
  if m>1 then write(' ');
  dispose(t); dec(m);
end;
begin
  read(m,s,n,k);
  new(head);
  head^.num:=1; now:=head;
  for i:=2 to m do
  begin
    new(t);
    now^.next:=t; t^.last:=now; now:=t; now^.num:=i;
  end;
  head^.last:=now; now^.next:=head;
  now:=head;
  for i:=1 to s-1 do now:=now^.next;
  while m>0 do
  begin
    for j:=1 to n-1 do now:=now^.next;
    t:=now;
    now:=now^.last;
    delete;
    if m=0 then break;
    for j:=1 to k-1 do now:=now^.last;
    t:=now;
    now:=now^.next;
    delete;
  end;
end.