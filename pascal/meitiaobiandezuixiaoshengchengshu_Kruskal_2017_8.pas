//PrayerOJ 1823
//TLE
var
  u,v,w,h,h1:array[1..10000] of longint;
  f:array[1..1000] of integer;
  n,m,i,j,t,a,b:integer;
  ans:int64;
function gf(k:integer):integer;
begin
  if f[k]=k then exit(k);
  f[k]:=gf(f[k]);
  exit(f[k]);
end;
procedure swap(var a,b:longint);
begin
  t:=a; a:=b; b:=t;
end;
procedure sort(l,r:longint);
var i,j,x:longint;
begin
  i:=l; j:=r; x:=w[(l+r)div 2];
  repeat
    while w[i]<x do inc(i);
    while x<w[j] do dec(j);
    if i<=j then
    begin
      swap(u[i],u[j]); swap(v[i],v[j]); swap(w[i],w[j]); swap(h[i],h[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  read(n,m);
  for i:=1 to m do
  begin
    read(u[i],v[i],w[i]);
    h[i]:=i;
  end;
  sort(1,m);
  for i:=1 to m do h1[h[i]]:=i;
  for i:=1 to m do
  begin
    for j:=1 to n do f[j]:=j;
    t:=1; j:=1; f[u[h1[i]]]:=v[h1[i]]; ans:=w[h1[i]];
    while t<n-1 do
    begin
      if j<>h1[i] then
      begin
        a:=gf(u[j]); b:=gf(v[j]);
        if a<>b then
        begin
          f[a]:=b;
          inc(t); inc(ans,w[j]);
        end;
      end;
      inc(j);
    end;
    writeln(ans);
  end;
end.
