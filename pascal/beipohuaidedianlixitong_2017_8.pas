program beipohuaidedianlixitong_2017_8;
//ParyerOJ 1118
const oo=200000000;
var
  c:array[1..1000,1..1000] of real;
  x,y:array[1..1000] of longint;
  v:array[1..1000] of boolean;
  d:array[0..1000] of real;
  n,w,p1,p2,i,j,k:integer;
  m:real;
begin
  read(n,w,m);
  for i:=1 to n do
  begin
    read(x[i],y[i]);
    for j:=1 to i-1 do
    begin
      c[i,j]:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
      if c[i,j]>m then c[i,j]:=oo;
      c[j,i]:=c[i,j];
    end;
    d[i]:=oo;
  end;
  d[0]:=oo; d[1]:=0;
  for i:=1 to w do
  begin
    read(p1,p2);
    c[p1,p2]:=0; c[p2,p1]:=0;
  end;
  for i:=1 to n do
  begin
    k:=0;
    for j:=1 to n do
      if not v[j]and(d[j]<d[k]) then k:=j;
    v[k]:=true;
    for j:=1 to n do
      if not v[j]and(d[k]+c[k,j]<d[j]) then d[j]:=d[k]+c[k,j];
  end;
  if d[n]=oo
  then write(-1)
  else write(trunc(d[n]*1000));
end.