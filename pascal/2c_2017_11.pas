//PrayerOJ 2075
const m=1000000007;
var
  a:array[0..100000] of longint;
  s,t,ans:int64;
  n,i:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  sort(1,n);
  inc(n);
  a[0]:=a[1]; a[n]:=maxlongint;
  for i:=1 to n do
  begin
    if a[i]>a[i-1] then
    begin
      t:=t*(t-1)mod m; ans:=(ans+t*s)mod m; s:=(s+t)mod m; t:=0;
    end;
    inc(t);
  end;
  write(ans);
end.