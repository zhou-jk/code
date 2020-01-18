program codevs_1154_nengliangxianglian_DP_2017_4_9;
var
  f:array[1..198,1..199] of longint;
  a:array[1..200] of integer;
  n,i,j,k,ans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  max:=b;
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    a[i+n]:=a[i];
  end;
  for i:=2*n-2 downto 1 do
  begin
    for j:=i+1 to 2*n-1 do
      for k:=i to j-1 do f[i,j]:=max(f[i,j],f[i,k]+f[k+1,j]+a[i]*a[k+1]*a[j+1]);
    ans:=max(ans,f[i,i+n-1]);
  end;
  writeln(ans);
end.