program htm_1002_daodanlanjiejiandansosuoban_dfs_2017_1_22;
var
  a:array[1..20] of integer;
  n,i,ans:byte;
procedure dfs(k,s:byte;t:integer);
begin
  if k=n+1 then
  begin
    if s>ans then ans:=s;
    exit;
  end;
  if a[k]>t then dfs(k+1,s+1,a[k]);
  dfs(k+1,s,t);
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  dfs(1,0,0);
  writeln(ans);
end.
