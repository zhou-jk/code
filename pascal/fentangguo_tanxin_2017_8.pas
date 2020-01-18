//PrayerOJ 1213
var
  a:array[1..100000] of longint;
  m,n,i,t:longint;
  ans,s:int64;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  read(m,n);
  s:=-m;
  for i:=1 to n do
  begin
    read(a[i]);
    inc(s,a[i]);
  end;
  sort(1,n);
  for i:=1 to n do
  begin
    t:=min(a[i],s div(n-i+1));
    dec(s,t); inc(ans,t*t);
  end;
  write(ans);
end.