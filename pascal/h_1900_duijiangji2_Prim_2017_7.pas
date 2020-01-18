program h_1900_duijiangji2_Prim_2017_7_14;
var
  x,y:array[1..1000] of integer;
  b:array[1..1000] of boolean;
  d:array[1..1000] of real;
  n,i,j,k:integer;
  a:real;
function min(a,b:real):real;
begin
  if a<b then exit(a);
  min:=b;
end;
begin
  readln(n);
  for i:=1 to n do readln(x[i],y[i]);
  fillchar(d,sizeof(d),127);
  d[1]:=0;
  for i:=1 to n do
  begin
    k:=-1;
    for j:=1 to n do
      if not b[j]and((k=-1)or(d[j]<d[k])) then k:=j;
    b[k]:=true;
    if d[k]>a then a:=d[k];
    for j:=1 to n do
      if not b[j] then
        d[j]:=min(d[j],sqr(x[k]-x[j])+sqr(y[k]-y[j]));
  end;
  if trunc(a)<a then a:=trunc(a)+1;
  writeln(a:0:0);
end.

