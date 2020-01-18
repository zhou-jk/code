//PrayerOJ 1568
var
  n,i:integer;
  a:real;
begin
  read(n);
  for i:=1 to n do
    if i mod 2=1
    then a:=a+1/i
    else a:=a-1/i;
  write(a:0:4);
end.