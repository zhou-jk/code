//PrayerOJ
var
  f:array[0..2000,0..2000] of longint;
  a:array[1..2000] of integer;
  n,i,j,ans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
  begin
    f[i,0]:=f[i-1,0]+a[n-i+1]*i;
    for j:=1 to i-1 do f[i,j]:=max(f[i-1,j]+a[n-(i-j)+1]*i,f[i-1,j-1]+a[j]*i);
    f[i,i]:=f[i-1,i-1]+a[i]*i;
  end;
  ans:=f[n,0];
  for i:=1 to n do ans:=max(ans,f[n,i]);
  writeln(ans);
end.
