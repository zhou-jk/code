program codevs_1003_dianhualianxian_Prim_2017_6_13;
var
  g:array[1..100,1..100] of integer;
  r,d,s:array[1..100] of integer;
  v:array[1..100] of boolean;
  n,i,j,k,m,a:longint;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do read(g[i,j]);
  fillchar(d,sizeof(d),127);
  d[1]:=0;
  for i:=1 to n do
  begin
    k:=-1;
    for j:=1 to n do
      if not v[j]and((k=-1)or(d[j]<d[k])) then k:=j;
    if k=-1 then break;
    v[k]:=true;
    if d[k]>0 then
    begin
      inc(m); inc(a,d[k]);
      r[m]:=k;
    end;
    for j:=1 to n do
      if not v[j]and(g[k,j]<d[j]) then
      begin
        d[j]:=g[k,j]; s[j]:=k;
      end;
  end;
  writeln(m);
  for i:=1 to m do
    if s[r[i]]<r[i]
    then writeln(s[r[i]],' ',r[i])
    else writeln(r[i],' ',s[r[i]]);
  writeln(a);
end.