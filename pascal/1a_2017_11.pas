//PrayerOJ 2077
const x:array[1..5] of byte=(1,0,0,0,1);
var
  n,a:array[1..1005] of byte;
  s:ansistring;
  i,j,l:integer;
begin
  read(s);
  l:=length(s);
  for i:=1 to l do val(s[i],n[l-i+1]);
  for i:=1 to 5 do
    for j:=1 to l do inc(a[i+j-1],n[j]*x[i]);
  inc(l,4);
  for i:=1 to l do
  begin
    inc(a[i+1],a[i]div 2);
    a[i]:=a[i]mod 2;
  end;
  if a[l+1]>0 then inc(l);
  for i:=l downto 1 do write(a[i]);
end.