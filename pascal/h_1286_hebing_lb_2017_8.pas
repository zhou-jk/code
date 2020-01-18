program h_1286_hebing_lianbiao_2017_8_11;
type node=record
            num:integer;
            next:^node;
          end;
var
  c1,c2,t,a:^node;
  n,i:integer;
begin
  readln(n);
  c1:=nil;
  for i:=1 to n do  // bottom up
  begin
    new(t);
    read(t^.num);
    t^.next:=c1; c1:=t;
  end;
  c2:=nil;
  for i:=1 to n do
  begin
    new(t);
    read(t^.num);
    t^.next:=c2; c2:=t;
  end;
  a:=nil;
  while (c1<>nil)and(c2<>nil) do
  begin
    new(t);
    if c1^.num>c2^.num
    then begin
           t^.num:=c1^.num;
           c1:=c1^.next;
         end
    else begin
           t^.num:=c2^.num;
           c2:=c2^.next;
        end;
    t^.next:=a; a:=t;
  end;
  while c1<>nil do
  begin
    new(t);
    t^.num:=c1^.num; t^.next:=a; a:=t;
    c1:=c1^.next;
  end;
  while c2<>nil do
  begin
    new(t);
    t^.num:=c2^.num; t^.next:=a; a:=t;
    c2:=c2^.next;
  end;
  for i:=1 to 2*n do
  begin
    write(a^.num:4);
    a:=a^.next;
  end;
end.
