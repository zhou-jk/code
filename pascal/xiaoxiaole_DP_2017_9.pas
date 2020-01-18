//PrayerOJ 1424
var
  f:array[1..248,1..248] of integer;
  n,i,j,k,ans:integer;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  read(n);
  for i:=1 to n do read(f[i,i]);
  for i:=n downto 1 do
    for j:=i+1 to n do
      for k:=i to j-1 do
        if (f[i,k]=f[k+1,j])and(f[i,k]>0) then f[i,j]:=max(f[i,j],f[i,k]+1);
  for i:=1 to n do
    for j:=i to n do ans:=max(ans,f[i,j]);
  write(ans);
end.