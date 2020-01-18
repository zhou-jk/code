program codevs_2189shuzisanjiaoxingW_dfs_2016_12_30;
var
  a:array[1..25,1..25]of integer;
  n,i,j,ans:integer;
procedure dfs(x,y,num:integer);
begin
  inc(num,a[x,y]);
  if x=n then
  begin
    if num mod 100>ans then ans:=num mod 100;
    exit;
  end;
  dfs(x+1,y,num);
  dfs(x+1,y+1,num);
end;
begin
  readln(n);
  for i:=1to n do
    for j:=1to i do read(a[i,j]);
  dfs(1,1,0);
  writeln(ans);
end.
