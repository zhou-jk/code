program codevs_1966_chenfayouxi_DP_2017_4_9;
var
  f:array[1..100,1..100] of longint;
  num:array[1..100] of byte;
  n,i,j,k:byte;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  min:=b;
end;
begin
  readln(n);
  for i:=1 to n do read(num[i]);
  for i:=n-2 downto 1 do
    for j:=i+2 to n do
    begin
      f[i,j]:=maxlongint;
      for k:=i+1 to j-1 do f[i,j]:=min(f[i,j],f[i,k]+f[k,j]+num[i]*num[k]*num[j]);
    end;
  writeln(f[1,n]);
end.