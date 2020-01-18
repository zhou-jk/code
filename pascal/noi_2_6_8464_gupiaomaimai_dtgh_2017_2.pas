program noi_2_6_8464_gupiaomaimai_dongtaiguihua_2017_2_5;
var
  a,f,g:array[0..100000] of longint;
  n,j,t,i,ans,min,max:longint;
function m(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(n);
    min:=1000000;
    for j:=1 to n do
    begin
      read(a[j]);
      if a[j]<min then min:=a[j];
      f[j]:=m(f[j-1],a[j]-min);
    end;
    max:=-1000000;
    for j:=n downto 1 do
    begin
      max:=m(max,a[j]);
      g[j]:=max-a[j];
    end;
    ans:=0;
    for j:=1 to n do ans:=m(ans,f[j]+g[j]);
    writeln(ans);
  end;
end.
