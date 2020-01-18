program h_1023_dizhuanjiaohuan_2017_3_4;
var
  f:array[0..10,0..10000] of longint;
  l:array[1..10] of byte;
  n,m,i,j,k:integer;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  readln(n,m);
  for i:=1 to n do readln(l[i]);
  for i:=0 to n do
    for j:=0 to m do f[i,j]:=2000000000;
  f[0,0]:=0;
  for i:=1 to n do
    for j:=i to m do
      for k:=1 to trunc(sqrt(j)) do f[i,j]:=min(f[i-1,j-k*k]+sqr(l[i]-k),f[i,j]);
  if f[n,m]=2000000000 then f[n,m]:=-1;
  writeln(f[n,m]);
end.
