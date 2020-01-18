//PrayerOJ 1026
var
  p,s,a:array[1..1001] of longint;
  n,b,i,ans:longint;
  sum:int64;
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
  read(n,b);
  for i:=1 to n do
  begin
    read(p[i],s[i]);
    a[i]:=p[i]+s[i];
  end;
  sort(1,n);
  inc(n);
  p[n]:=maxlongint div 2; s[n]:=maxlongint div 2; a[n]:=maxlongint;
  for i:=1 to n+1 do
  begin
    inc(sum,a[i]);
    if sum>b then break;
    inc(ans);
  end;
  if sum-a[i]+p[i]div 2+s[i]<=b then inc(ans);
  write(ans);
end.