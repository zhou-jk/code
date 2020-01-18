program h_1763_qushuyouxi_DP_2017_4_8;
var
  f:array[1..200,0..200] of longint;
  num:array[1..200] of word;
  n,i,j:byte;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  max:=b;
end;
function sum(l,r:byte):longint;
var i:byte;
begin
  sum:=0;
  for i:=l to r do inc(sum,num[i]);
end;
begin
  readln(n);
  for i:=1 to 2*n do read(num[i]);
  for i:=2*n downto 1 do
    for j:=i to 2*n do f[i,j]:=max(num[i]+sum(i+1,j)-f[i+1,j],num[j]+sum(i,j-1)-f[i,j-1]);
  writeln(f[1,2*n]);
end.