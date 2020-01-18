//PrayerOJ 1114
var n:int64;
begin
  read(n);
  if n mod 2=1
  then write((n+1)*(n-1)*(n-3)div 12)
  else write(n*(n-2)*(n-4)div 12+n div 2-1);
end.
