program h_1899_duijiangji1_Floyed_2017_7_14;
var
  g:array[1..200,1..200] of boolean;
  x,y,p:array[1..200] of integer;
  n,i,j,k,a,ta:byte;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(x[i],y[i],p[i]);
    g[i,i]:=true;
  end;
  for i:=1 to n do
    for j:=1 to n do g[i,j]:=sqrt(sqr(abs(x[i]-x[j]))+sqr(abs(y[i]-y[j])))<=p[i];
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do g[i,j]:=g[i,j]or g[i,k]and g[k,j];
  for i:=1 to n do
  begin
    ta:=0;
    for j:=1 to n do
      if g[i,j] then inc(ta);
    if ta>a then a:=ta;
  end;
  writeln(a);
end.

