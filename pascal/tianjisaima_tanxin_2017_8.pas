//PrayerOJ 1183
uses math;
type arr=array[1..2000] of longint;
var
  f,g:array[0..2000,0..2000] of longint;
  n,i,j,a:longint;
  v1,v2:arr;
procedure sort(var a:arr;l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]>x do inc(i);
    while x>a[j] do dec(j);
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(a,l,j);
  if i<r then sort(a,i,r);
end;
begin
  read(n);
  for i:=1 to n do read(v1[i]);
  for i:=1 to n do read(v2[i]);
  sort(v1,1,n); sort(v2,1,n);
  for i:=1 to n do
    for j:=1 to n do
    begin
      if v1[i]<v2[j] then g[i,j]:=-200;
      if v1[i]>v2[j] then g[i,j]:=200;
    end;
  for i:=1 to n do
  begin
    f[i,0]:=f[i-1,0]+g[n-i+1,i];
    for j:=1 to i-1 do f[i,j]:=max(f[i-1,j]+g[n-(i-j)+1,i],f[i-1,j-1]+g[j,i]);
    f[i,i]:=f[i-1,i-1]+g[i,i];
  end;
  for i:=0 to n do a:=max(a,f[n,i]);
  write(a);
end.