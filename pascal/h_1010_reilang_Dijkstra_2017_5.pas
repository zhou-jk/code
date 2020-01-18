program h_1010_reilang_Dijkstra_2017_5_13;
var
  g:array[1..2500,1..2500] of integer;
  t,c,ts,te,rs,re,ci,i,j,k:integer;
  d:array[1..2500] of longint;
  b:array[1..2500] of boolean;
begin
  readln(t,c,ts,te);
  fillchar(g,sizeof(g),127);
  for i:=1 to c do
  begin
    readln(rs,re,ci);
    if ci<g[rs,re] then
    begin
      g[rs,re]:=ci; g[re,rs]:=ci;
    end;
  end;
  fillchar(d,sizeof(d),127);
  d[ts]:=0;
  for i:=1 to t do
  begin
    k:=0;
    for j:=1 to t do
      if not b[j]and((k=0)or(d[j]<d[k])) then k:=j;
    if k=0 then break;
    b[k]:=true;
    for j:=1 to t do
      if not b[j]and(d[k]+g[k,j]<d[j]) then d[j]:=d[k]+g[k,j];
  end;
  writeln(d[te]);
end.


