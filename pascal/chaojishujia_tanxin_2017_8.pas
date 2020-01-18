//PrayerOJ 1252
var
  h:array[1..20000] of longint;
  n,b,i,sum:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=h[(l+r)div 2];
  repeat
    while h[i]>x do inc(i);
    while x>h[j] do dec(j);
    if i<=j then
    begin
      y:=h[i]; h[i]:=h[j]; h[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  read(n,b);
  for i:=1 to n do read(h[i]);
  sort(1,n);
  for i:=1 to n do
  begin
    inc(sum,h[i]);
    if sum>=b then break;
  end;
  write(i);
end.