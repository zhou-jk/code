program noi_2_6_1481_MAXIMUMSUM_dongtaiguihua_2017_2_9;
var
  f,g,a:array[0..50000] of longint;
  t,n,i,j,ans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(n);
    g[0]:=-maxlongint;
    for j:=1 to n do
    begin
      read(a[j]);
      f[j]:=max(a[j],f[j-1]+a[j]);
      g[j]:=max(g[j-1],f[j]);
    end;
    f[n]:=a[n]; ans:=-maxlongint;
    for j:=n-1 downto 1 do
    begin
      f[j]:=max(a[j],f[j+1]+a[j]);
      ans:=max(ans,g[j]+f[j+1]);
    end;
    writeln(ans);
  end;
end.

