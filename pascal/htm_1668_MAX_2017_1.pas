program htm_1668_MAX_dfs_2017_1_25;
var
  x:array[1..18] of integer;
  ans:int64;
  n,i:byte;
procedure dfs(k,t:byte;s:int64);
begin
  if (t>0)and(s>ans) then ans:=s;
  if k=n+1 then exit;
  dfs(k+1,t+1,s*x[k]);
  dfs(k+1,t,s);
end;
begin
  readln(n);
  for i:=1 to n do readln(x[i]);
  ans:=-10;
  dfs(1,0,1);
  writeln(ans);
end.