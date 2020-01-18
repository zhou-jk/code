//PrayerOJ 1393
var
  a,b:array[1..5000] of longint;
  f:array[0..5000] of qword;
  n,i,j:integer;
function min(a,b:qword):qword;
begin
  if a<b then exit(a);
  exit(b);
end;
procedure sort(l,r:integer);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=b[(l+r)div 2];
  repeat
    while b[i]<x do inc(i);
    while x<b[j] do dec(j);
    if i<=j then
    begin
      y:=b[i]; b[i]:=b[j]; b[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  b:=a;
  sort(1,n);
  f[0]:=100000000000000;
  for i:=1 to n do
    for j:=1 to n do f[j]:=min(f[j]+abs(a[i]-b[j]),f[j-1]);
  write(f[n]);
end.