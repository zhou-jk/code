program h_1238_tiaoshitou_erfenchazhao_2017_8_17;
var
  d:array[0..50001] of longint;
  len,n,m,i,l,r,mid,s,t:longint;
function check(l:longint):boolean;
begin
  i:=1; t:=0;
  while i<=n do
  begin
    s:=0;
    while (s<l)and(i<=n) do
    begin
      inc(s,d[i]-d[i-1]);
      inc(i); inc(t);
    end;
    dec(t);
    if (t>m)or(s<l) then exit(false);
  end;
  exit(true);
end;
begin
  read(len,n,m);
  for i:=1 to n do read(d[i]);
  inc(n); d[n]:=len;
  l:=1; r:=len;
  while l<=r do
  begin
    mid:=(l+r)div 2;
    if check(mid)
    then l:=mid+1
    else r:=mid-1;
  end;
  write(r);
end.

