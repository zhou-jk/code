program a21;
var
  a,c:longint;
  b,d,e:real;
begin
  readln(b,a,d);
  e:=d/12;
  for c:=1 to a do
    begin
      b:=b*(1+e);
      b:=round(b);
    end;
  writeln(b:0:0,' ',e:0:100);
end.
