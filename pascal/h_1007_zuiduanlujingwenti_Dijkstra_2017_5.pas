program h_1007_zuiduanlujingwenti_Dijkstra_2017_5_13;
var
  g:array[1..100,1..100] of boolean;
  x,y:array[1..100] of integer;
  b:array[1..100] of boolean;
  d:array[1..100] of real;
  n,m,s,t,i,j,k:integer;
begin
  readln(n);
  for i:=1 to n do readln(x[i],y[i]);
  readln(m);
  for i:=1 to n do d[i]:=10000000;
  for i:=1 to m do
  begin
    readln(j,k);
    g[j,k]:=true; g[k,j]:=true;
  end;
  readln(s,t);
  d[s]:=0; b[s]:=true;
  for i:=1 to n do
    if g[s,i] then d[i]:=sqrt(sqr(x[s]-x[i])+sqr(y[s]-y[i]));
  for i:=1 to n do
  begin
    k:=-1;
    for j:=1 to n do
      if not b[j]and((k=-1)or(d[j]<d[k])) then k:=j;
    if k=-1 then break;
    b[k]:=true;
    for j:=1 to n do
      if not b[j]and g[j,k]and(d[k]+sqrt(sqr(x[k]-x[j])+sqr(y[k]-y[j]))<d[j]) then d[j]:=d[k]+sqrt(sqr(x[k]-x[j])+sqr(y[k]-y[j]));
  end;
  writeln(d[t]:0:2);
end.
