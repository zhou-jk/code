//PrayerOJ 1414
var
  f,a:array[0..1000] of integer;
  n,i,j,ans:integer;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  read(n);
  for i:=1 to n do
  begin
    read(a[i]);
    f[i]:=-maxint;
    if a[i]<=i then
      for j:=0 to i-1 do
        if (a[i]>a[j])and(a[i]-a[j]<=i-j) then f[i]:=max(f[i],f[j]);
    inc(f[i]);
  end;
  for i:=1 to n do ans:=max(ans,f[i]);
  write(ans);
end.


