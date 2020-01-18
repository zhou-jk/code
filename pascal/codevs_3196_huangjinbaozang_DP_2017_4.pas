program codevs_3196_huangjnbaozang_DP_2017_4_9;
var
  f:array[1..500,0..500] of longint;
  num:array[1..500] of word;
  n,i,j:integer;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  max:=b;
end;
function sum(l,r:integer):longint;
var i:integer;
begin
  sum:=0;
  for i:=l to r do inc(sum,num[i]);
end;
begin
  readln(n);
  for i:=1 to n do read(num[i]);
  for i:=n downto 1 do
    for j:=i to n do f[i,j]:=max(num[i]+sum(i+1,j)-f[i+1,j],num[j]+sum(i,j-1)-f[i,j-1]);
  writeln(f[1,n],' ',sum(1,n)-f[1,n]);
end.
