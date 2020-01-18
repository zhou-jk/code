program codevs_1078_zuixiaoshengchengshu_Prim_2017_6_13;
var
  g:array[1..100,1..100] of longint;
  dist:array[1..100] of longint;
  vis:array[1..100] of boolean;
  n,i,j,k,ans:longint;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do read(g[i,j]);
  fillchar(dist,sizeof(dist),127);
  dist[1]:=0;
  for i:=1 to n do
  begin
    k:=-1;
    for j:=1 to n do
      if not vis[j]and((k=-1)or(dist[j]<dist[k])) then k:=j;
    if k=-1 then break;
    vis[k]:=true;
    inc(ans,dist[k]);
    for j:=1 to n do
      if not vis[j]and(g[k,j]<dist[j]) then dist[j]:=g[k,j];
  end;
  writeln(ans);
end.


