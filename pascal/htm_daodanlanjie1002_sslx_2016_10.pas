program htm_daodanlanjie1002_shensolianxi_2016_11_6;
var
  n,i,ans:integer;
  a:array[1..20] of integer;
procedure dfs(k,t,s:integer);
begin
  if s>ans then ans:=s;
  if k=n+1 then exit;
  dfs(k+1,t,s);
  if a[k]>t then dfs(k+1,a[k],s+1);
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  dfs(1,0,0);
  writeln(ans);
end.