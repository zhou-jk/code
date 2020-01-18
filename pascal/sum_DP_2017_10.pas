//PrayerOJ 2000 tyvj 1089 smrtfun
var
  f:array[-100000..100000] of longint;
  g:array[-100000..100000] of boolean;
  a,b:array[1..100] of integer;
  n,i,j,s1,s2,ans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure solve(i,j:longint);
begin
  if g[j-a[i]] then
  begin
    f[j]:=max(f[j],f[j-a[i]]+b[i]);
    g[j]:=true;
  end;
end;
begin
  read(n);
  for i:=1 to n do
  begin
    read(a[i],b[i]);
    if a[i]<0
    then inc(s1,a[i])
    else inc(s2,a[i]);
  end;
  for i:=s1 to s2 do f[i]:=-maxlongint;
  g[0]:=true; f[0]:=0;
  for i:=1 to n do
    if a[i]>0
    then for j:=s2 downto s1 do solve(i,j)
    else for j:=s1 to s2 do solve(i,j);
  for i:=s2 downto max(s1,1) do
    if g[i]and(f[i]>=0) then ans:=max(ans,f[i]+i);
  write(ans);
end.