//PrayerOJ 1320
type node=record
            num:longint;
            next:^node;
          end;
var
  head,now,tmp:^node;
  n,x,i:longint;
begin
  read(n);
  new(head);
  head^.num:=-maxlongint;
  now:=head;
  for i:=1 to n do
  begin
    new(tmp);
    read(tmp^.num);
    now^.next:=tmp; now:=tmp;
  end;
  new(now^.next);
  now^.next^.num:=maxlongint;
  read(x);
  now:=head;
  for i:=1 to n+1 do
  begin
    if now^.next^.num>=x then
    begin
      new(tmp);
      tmp^.next:=now^.next; tmp^.num:=x; now^.next:=tmp;
      break;
    end;
    now:=now^.next;
  end;
  now:=head^.next;
  for i:=1 to n+1 do
  begin
    write(now^.num:4);
    now:=now^.next;
  end;
end.