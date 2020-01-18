program htm_xuanshu1034_shensolianxi_2016_10_31;
var
  n,k,i,ans:integer;
  x:array[1..20] of longint;
procedure dfs(t,s:integer;num:longint);
var
  i:integer;
begin
  if s=k then
  begin
    for i:=2 to trunc(sqrt(num)) do
      if num mod i=0 then exit;
    inc(ans);
    exit;
  end;
  if t=n+1 then exit;
  dfs(t+1,s,num);
  dfs(t+1,s+1,num+x[t]);
end;
begin
  readln(n,k);
  for i:=1 to n do
    read(x[i]);
  dfs(1,0,0);
  writeln(ans);
end.



