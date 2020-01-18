var
  a,b:int64;
  i:longint;
begin
  a:=100*33*49;
  for i:=99 downto 2 do
    b:=b+i*(i-1);
  writeln(a,' ',b);
  readln;
end.