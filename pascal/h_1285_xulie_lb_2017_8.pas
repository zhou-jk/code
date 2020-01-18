program h_1285_xulie_lianbiao_2017_8_11;
type node=record
             num:byte;
             next:^node;
          end;
var
  head,now,t:^node;
  n,i,m,p,tmp:byte;
begin
  readln(n);
  new(head);
  read(head^.num);
  now:=head;
  m:=now^.num;
  p:=1;
  for i:=2 to n do
  begin
    new(t);
    read(t^.num);
    if t^.num<m then
    begin
      m:=t^.num;
      p:=i;
    end;
    now^.next:=t; now:=t;
  end;
  now:=head;
  for i:=1 to p-1 do now:=now^.next;
  tmp:=now^.num; now^.num:=head^.num; head^.num:=tmp;
  now:=head;
  write(now^.num:4);
  for i:=1 to n-1 do
  begin
    now:=now^.next;
    write(now^.num:4);
  end;
end.


