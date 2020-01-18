//PrayerOJ 2067
var
  n,t,a,i,s:longint;
begin
  read(n,t);
  for i:=1 to n do
  begin
    read(a);
    inc(s,86400-a);
    if s>=t then
    begin
      write(i);
      break;
    end;
  end;
end.
