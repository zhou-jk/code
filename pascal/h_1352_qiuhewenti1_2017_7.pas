program h_1352_qiuhewenti1_2017_7_17;
var
  n,m,i,a:longint;
begin
  readln(n,m);
  a:=1;
  for i:=1 to n do a:=a*m mod 10007;
  writeln(a);
end.