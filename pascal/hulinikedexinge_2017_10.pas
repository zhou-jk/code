//PrayerOJ 1614
var
  t,l,s,a:array[1..50001] of longint;
  n,q,b,i,j,tmp:longint;
procedure swap(var a,b:longint);
begin
  tmp:=a; a:=b; b:=tmp;
end;
procedure sort(l,r:longint);
var i,j,x:longint;
begin
  i:=l; j:=r; x:=t[(l+r)div 2];
  repeat
    while t[i]<x do inc(i);
    while x<t[j] do dec(j);
    if i<=j then
    begin
      swap(t[i],t[j]); swap(s[i],s[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  read(n,q);
  for i:=1 to n do
  begin
    read(b);
    l[i+1]:=l[i]+b;
  end;
  for i:=1 to q do
  begin
    read(t[i]);
    s[i]:=i;
  end;
  sort(1,q);
  j:=1;
  for i:=1 to q do
  begin
    while t[i]>=l[j+1] do inc(j);
    a[s[i]]:=j;
  end;
  for i:=1 to q do writeln(a[i]);
end.