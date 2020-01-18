program htm_1219_kaixingdejinming_dfs_2017_1_25;
var
  v,p:array[1..25] of integer;
  n,m,ans,i:longint;
procedure dfs(k,s,t:longint);
begin
  if t>n then exit;
  if s>ans then ans:=s;
  if k=m+1 then exit;
  dfs(k+1,s+v[k]*p[k],t+v[k]);
  dfs(k+1,s,t);
end;
begin
  readln(n,m);
  for i:=1 to m do readln(v[i],p[i]);
  dfs(1,0,0);
  writeln(ans);
end.