program h_1353_qiuhewenti2_2017_7_17;
var
  f:array[1..100,1..100] of longint;
  n,m,i,j,a:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    f[i,1]:=1;
    f[i,i]:=1;
  end;
  for i:=2 to n do
    for j:=2 to min(i-1,m) do
      f[i,j]:=(j*f[i-1,j]+f[i-1,j-1])mod 10007;
  for i:=1 to min(n,m) do a:=a+f[n,i];
  writeln(a mod 10007);
end.
