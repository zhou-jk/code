program huashengcaizhai_tanxin_2017_8_19;
//PrayerOJ 1231
var
  x,y,p:array[1..401] of integer;
  m,n,k,i,j,t,s,a:longint;
procedure swap(var a,b:integer);
var t:integer;
begin
  t:=a; a:=b; b:=t;
end;
procedure sort(l,r:integer);
var i,j,t:integer;
begin
  i:=l; j:=r; t:=p[(l+r)div 2];
  repeat
    while p[i]>t do inc(i);
    while t>p[j] do dec(j);
    if i<=j then
    begin
      swap(p[i],p[j]); swap(x[i],x[j]); swap(y[i],y[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  read(m,n,k);
  for i:=1 to m do
    for j:=1 to n do
    begin
      inc(t);
      x[t]:=i; y[t]:=j;
      read(p[t]);
    end;
  sort(1,t);
  s:=x[1];
  for i:=1 to t do
  begin
    inc(s);
    if s+x[i]>k then break;
    inc(a,p[i]);
    inc(s,abs(x[i+1]-x[i])+abs(y[i+1]-y[i]));
  end;
  write(a);
end.