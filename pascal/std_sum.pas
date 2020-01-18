var
  n,ans:longint;
procedure dfs(k,s:longint);
begin
  if k=n then
  begin
    if s=n then inc(ans);
    exit;
  end;
  dfs(k+1,s-k);
  dfs(k+1,s+k);
end;
begin
  readln(n);
  dfs(2,-1);
  writeln(ans);
end.