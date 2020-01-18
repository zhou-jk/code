program h_1402_jiandanyuesefuwenti_lianbiao_2017_8_11;
type node=record
            num:byte;
            next:^node;
          end;
var
  head,now,t:^node;
  n,m,i,j:byte;
begin
  readln(n,m);
  new(head);
  head^.num:=1; now:=head;
  for i:=2 to n do
  begin
    new(t);
    now^.next:=t; now:=t; now^.num:=i;
  end;
  now^.next:=head;
  now:=head;
  for i:=1 to n-1 do
  begin
    for j:=1 to m-2 do now:=now^.next;
    t:=now^.next; now^.next:=t^.next;
    now:=now^.next;
    dispose(t);
  end;
  writeln(now^.num);
end.