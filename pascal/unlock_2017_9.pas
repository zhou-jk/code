//PrayerOJ 1289
var
  a:array[1..100000] of longint;
  n,k,t,i:longint;
  ans:qword;
begin
  read(n,k);
  for i:=1 to n do
  begin
    read(t);
    a[t]:=i;
  end;
  for i:=2 to n do inc(ans,(a[i]-a[i-1]+n)mod n);
  t:=(a[1]-a[n]+n)mod n;
  inc(ans,t);
  ans:=k div n*ans;
  if k mod n=0 then dec(ans,t);
  inc(ans,a[1]-1);
  for i:=2 to k mod n do inc(ans,(a[i]-a[i-1]+n)mod n);
  write(ans);
end.


