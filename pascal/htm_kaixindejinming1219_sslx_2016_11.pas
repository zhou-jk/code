program htm_kaixindejinming1219_shensolianxi_2016_11_6;
var
  n,m,i,ans:longint;
  v,p:array[1..25] of longint;
procedure dfs(k,num,mon:longint);
begin
  if mon>n then exit;
  if num>ans then ans:=num;
  if k=m+1 then exit;
  dfs(k+1,num,mon);
  dfs(k+1,num+v[k]*p[k],mon+v[k]);
end;
begin
  readln(n,m);
  for i:=1 to m do readln(v[i],p[i]);
  dfs(1,0,0);
  writeln(ans);
end.