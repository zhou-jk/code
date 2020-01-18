program tm_yhlx;
var
  m:extended;
  y,a:longint;
  r:real;
begin
  readln(r,m,y);
  r:=r/100;
  for a:=1 to y do
    m:=m*(1+r);
  m:=trunc(m);
  writeln(m:0:0);
end.
