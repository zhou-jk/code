program h_1115_dajing_Prim_2017_6_14;
var
  g:array[0..300,1..300] of longint; //0..300,0..300
  d:array[0..300] of longint;
  v:array[0..300] of boolean;
  n,i,j,k,ans:longint;
begin
  readln(n);
  fillchar(g[0],1200,127); fillchar(d,1204,127);
  for i:=1 to n do readln(g[0,i]);  //g[i,0]:=g[0,i];
  for i:=1 to n do
    for j:=1 to n do read(g[i,j]);
  d[0]:=0;
  for i:=0 to n do
  begin
    k:=-1;
    for j:=0 to n do
      if not v[j]and((k=-1)or(d[j]<d[k])) then k:=j;
    v[k]:=true;
    inc(ans,d[k]);
    for j:=1 to n do //0 to n
      if not v[j]and(g[k,j]<d[j]) then d[j]:=g[k,j];
  end;
  writeln(ans);
end.
