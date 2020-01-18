//PrayerOJ 2089
var
  c:array[1..1000000] of integer;
  n,t,i,l,r,s,a:longint;
begin
  read(n,t);
  for i:=1 to n do read(c[i]);
  a:=maxlongint;
  while r<n do
  begin
    while (r<n)and(s<t) do
    begin
      inc(r); inc(s,c[r]);
    end;
    while s>=t do
    begin
      if r-l<a then a:=r-l;
      inc(l); dec(s,c[l]);
    end;
  end;
  if a=maxlongint
  then write('Angry')
  else write(a);
end.