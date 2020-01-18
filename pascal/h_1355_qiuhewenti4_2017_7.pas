program h_1355_qiuhewenti4_2017_7_18;
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
    f[i,i]:=1;
    f[i,1]:=1;
  end;
  for i:=3 to n do
    for j:=2 to min(i-1,m) do f[i,j]:=(f[i-1,j-1]+f[i-j,j])mod 10007;
  for i:=1 to min(n,m) do a:=a+f[n,i];
  writeln(a mod 10007);
end.
