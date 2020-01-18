program h_1221_lajixianjing_2017_3_4;
var
  t,ff,h,f:array[0..101] of integer;
  d,g,i,j:integer;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  max:=b;
end;
procedure stop(n:integer);
begin
  writeln(n);
  halt;
end;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=t[(l+r) div 2];
  repeat
    while t[i]<x do inc(i);
    while x<t[j] do dec(j);
    if i<=j then
    begin
      y:=t[i]; t[i]:=t[j]; t[j]:=y;
      y:=ff[i]; ff[i]:=ff[j]; ff[j]:=y;
      y:=h[i]; h[i]:=h[j]; h[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(d,g);
  f[0]:=10;
  //for i:=1 to d do f[i]:=-1;
  for i:=1 to g do readln(t[i],ff[i],h[i]);
  sort(1,g);
  for i:=1 to g do
  begin
    for j:=d downto 0 do
    begin
      if f[j]>0 then dec(f[j],t[i]-t[i]-ff[i]);
      if j>=h[i] then
        if f[j-h[i]]>0 then f[j]:=max(f[j],f[j-h[i]]-t[i]+t[i-1]);
    end;
    if f[d]>0 then stop(t[i]);
    if t[i+1]-t[i]>=f[0] then stop(t[i]+f[0]);
  end;
  writeln(t[g]+f[0]);
end.