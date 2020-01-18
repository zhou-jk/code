//PrayerOJ 1994
var
  s:array[0..10000] of boolean;
  a:array[1..100] of integer;
  n,i,j,c:byte;
begin
  read(n);
  for i:=1 to n do
  begin
    read(a[i]);
    s[a[i]]:=true;
  end;
  for i:=1 to n do
    for j:=1 to n do
      if (a[i]>a[j])and s[a[i]-a[j]]and(a[i]-a[j]<>a[j]) then
      begin
        inc(c);
        break;
      end;
  write(c);
end.
