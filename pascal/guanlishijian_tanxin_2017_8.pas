//PrayerOJ 1032
var
  t,s:array[1..1000] of longint;
  n,i,tmp:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a; a:=b; b:=t;
end;
procedure sort(l,r:longint);
var i,j,x:longint;
begin
  i:=l; j:=r; x:=s[(l+r)div 2];
  repeat
    while s[i]>x do inc(i);
    while x>s[j] do dec(j);
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
  read(n);
  for i:=1 to n do read(t[i],s[i]);
  sort(1,n);
  tmp:=s[1];
  for i:=1 to n do
    tmp:=min(tmp,s[i])-t[i];
  if tmp<0 then tmp:=-1;
  write(tmp);
end.