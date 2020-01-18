program codevs_1203panduanfudianshushifouxiangdeng_2017_1_6;
var
  a,b:real;
begin
  readln(a,b);
  if abs(a-b)<=1e-8
  then writeln('yes')
  else writeln('no');
end.
