program h_1119_baihua_DP_2017_8_4;
var
  f:array[0..100,0..100] of longint;
  a:array[1..100] of byte;
  n,m,i,j,k:byte;
function min(a,b:byte):byte;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  readln(n,m);
  for i:=1 to n do read(a[i]);
  //for i:=1 to m do f[0,i]:=0;
  for i:=0 to n do f[i,0]:=1;
  for i:=1 to n do
    for j:=1 to m do
      for k:=0 to min(a[i],j) do f[i,j]:=(f[i,j]+f[i-1,j-k])mod 1000007;
  writeln(f[n,m]);
end.