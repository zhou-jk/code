program h_1900_duijiangji2_Kruskal_2017_7_14;
type edge=record
            x,y:integer;
            l:real;
          end;
var
  x,y,f:array[1..1000] of integer;
  e:array[0..500000] of edge;
  n,i,j,k,fa,fb:longint;
  a:real;
function gf(k:integer):integer;
begin
  if f[k]=k then exit(k);
  f[k]:=gf(f[k]);
  gf:=f[k];
end;
procedure sort(l,r:longint);
var
  i,j:longint;
  x:real;
  y:edge;
begin
  i:=l; j:=r; x:=e[(l+r)div 2].l;
  repeat
    while e[i].l<x do inc(i);
    while x<e[j].l do dec(j);
    if i<=j then
    begin
      y:=e[i]; e[i]:=e[j]; e[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(x[i],y[i]);
    f[i]:=i;
  end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
    begin
      inc(k);
      e[k].x:=i; e[k].y:=j; e[k].l:=sqr(x[i]-x[j])+sqr(y[i]-y[j]);
    end;
  sort(1,k);
  i:=1; j:=0;
  while j<n-1 do
    with e[i] do
    begin
      fa:=gf(x); fb:=gf(y);
      if fa<>fb then
      begin
        inc(j);
        f[fa]:=fb;
      end;
      inc(i);
    end;
  with e[i-1] do a:=l;
  if trunc(a)<a
  then a:=trunc(a)+1;
  writeln(a:0:0);
end.

