program htm_1280_zhuangzaiwenti_dfs_2017_1_25;
var
  w,f:array[1..31] of integer;
  n,c,i,ans:integer;
procedure dfs(k,m:integer);
begin
  if m>c then exit;
  if m>ans then ans:=m;
  if k=n+1 then exit;
  if m+f[k]<=ans then exit;
  dfs(k+1,m+w[k]);
  dfs(k+1,m);
end;
begin
  readln(n,c);
  for i:=1 to n do read(w[i]);
  for i:=n downto 1 do f[i]:=f[i+1]+w[i];
  dfs(1,0);
  writeln(ans);
end.
