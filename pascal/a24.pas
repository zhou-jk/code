program a24;
var
  a,b:longint;
  c,d:extended;
begin
  readln(a);
  d:=1;
  c:=0;
  for b:=1 to a do
    begin
      d:=d*b;
      c:=c+d;
    end;
  writeln(c:20:0);
end.
