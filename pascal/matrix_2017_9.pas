//PrayerOJ 1969
var n,i,j,s,t,l:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  read(n,i,j);
  s:=min(min(i,n-i+1),min(j,n-j+1));
  l:=n-2*s+2;
  if i=s then t:=j-s+1;
  if j=n-s+1 then t:=l+i-s;
  if i=n-s+1 then t:=2*l+n-s-j;
  if j=s then t:=3*l-1+n-s-i;
  write(t+(4*(n-1)+4*(n-2*(s-2)-1))*(s-1)div 2);
end.


