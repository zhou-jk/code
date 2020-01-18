program a9;
var
  a,b:integer;
begin
  readln(a,b);
  if ((a mod 2=0)or(b mod 2=1)) and (a+b>10) then writeln('a')
else
  writeln('b');
end.