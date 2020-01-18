//PrayerOJ 1114
var
  n,ans,t,i:longint;
function calc(k:integer):longint;
begin
  if k<=t then exit(k-1);
  exit(k-1-2*(k-t));
end;
begin
  read(n);
  t:=(n+1)div 2;
  for i:=2 to n-2 do inc(ans,calc(i)*calc(n-i));
  write(ans);
end.