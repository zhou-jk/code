program h_1119_baihua_DB_2017_3_18;
var
  f:array[0..100,0..100]of longint;
  a:array[1..100]of byte;
  n,m,i,j,k:byte;
begin
  readln(n,m);
  for i:=1 to n do read(a[i]);
  for i:=0 to n do  f[i,0]:=1;
  for i:=1 to n do
    for j:=1 to m do
      for k:=0 to a[i] do
        if j>=k then f[i,j]:=(f[i,j]+f[i-1,j-k])mod 1000007;
  writeln(f[n,m]);
end.

