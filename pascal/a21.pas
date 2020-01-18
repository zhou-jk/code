program a21;
var
  a,c:longint;
  b:real;
begin
  readln(b,a);
  a:=a*24 div 10;
  for c:=1 to a do
    begin
      b:=b*1.05;
      b:=round(b);
    end;
  writeln(b:0:0);
end.