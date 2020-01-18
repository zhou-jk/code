//PrayerOJ 1414
var
  f:array[0..1000,-1..1000] of integer;
  n,a,i,j,ans:integer;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  read(n);
  for i:=1 to n do
  begin
    read(a);
    for j:=0 to i-1 do f[i,j]:=max(f[i-1,j-1],f[i-1,j]+integer(a=i-j));
  end;
  for i:=0 to n-1 do ans:=max(ans,f[n,i]);
  write(ans);
end.


