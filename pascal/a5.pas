program a5;
var
  a,b,c,d,e:int64;
begin
  readln(a,b,c);
  d:=(b-a) div c+1;
  e:=(a+b)*d div 2;
  writeln('=',e)
end.
