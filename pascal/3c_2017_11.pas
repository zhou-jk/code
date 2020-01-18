//PrayerOJ 2093
var
  x,y,z,f:array[1..90] of longint;
  n,tx,ty,tz,i,j,t,a:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure swap(var a,b:longint);
begin
  t:=a; a:=b; b:=t;
end;
procedure sort(l,r:longint);
var i,j,t:longint;
begin
  i:=l; j:=r; t:=x[(l+r)div 2];
  repeat
    while x[i]>t do inc(i);
    while t>x[j] do dec(j);
    if i<=j then
    begin
      swap(x[i],x[j]); swap(y[i],y[j]); swap(z[i],z[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  read(n);
  for i:=0 to n-1 do
  begin
    read(tx,ty,tz);
    t:=i*3+1; x[t]:=min(tx,ty); y[t]:=max(tx,ty); z[t]:=tz;
    t:=i*3+2; x[t]:=min(tx,tz); y[t]:=max(tx,tz); z[t]:=ty;
    t:=i*3+3; x[t]:=min(ty,tz); y[t]:=max(ty,tz); z[t]:=tx;
  end;
  n:=n*3;
  sort(1,n);
  f[1]:=z[1];
  for i:=2 to n do
  begin
    for j:=1 to i-1 do
      if (x[j]>x[i])and(y[j]>y[i]) then f[i]:=max(f[i],f[j]);
    inc(f[i],z[i]);
    a:=max(a,f[i]);
  end;
  write(a);
end.