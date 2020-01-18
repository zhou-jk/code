//PrayerOJ 1432
var
  len:array[1..100000] of longint;
  m,n,i,t,l,r,mid:longint;
function check(l:longint):boolean;
begin
  t:=0;
  for i:=1 to m do
  begin
    inc(t,len[i]div l);
    if t>=n then exit(true);
  end;
  exit(false);
end;
begin
  read(m,n);
  for i:=1 to m do
  begin
    read(len[i]);
    if len[i]>r then r:=len[i];
  end;
  l:=1;
  while l<=r do
  begin
    mid:=(l+r)div 2;
    if check(mid)
    then l:=mid+1
    else r:=mid-1;
  end;
  write(r);
end.
