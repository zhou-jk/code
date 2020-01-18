//PrayerOJ 1801
var
  x,y:array[1..100000] of longint;
  n,m,i,l,r,mid:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
function check(k:longint):boolean;
var t:longint;
begin
  t:=m;
  for i:=1 to n do
  begin
    if x[i]<k*y[i] then dec(t,k*y[i]-x[i]);
    if t<0 then exit(false);
  end;
  exit(true);
end;
begin
  read(n,m);
  for i:=1 to n do read(x[i]);
  for i:=1 to n do read(y[i]);
  r:=(x[1]+m)div y[1];
  for i:=2 to n do r:=min(r,(x[i]+m)div y[i]);
  while l<=r do
  begin
    mid:=(l+r)div 2;
    if check(mid)
    then l:=mid+1
    else r:=mid-1;
  end;
  write(r);
end.

