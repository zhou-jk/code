program codevs_qukandianying1570_shenso_2016_12_9;
var
  w:array[1..16] of integer;
  c,n,i,ans:integer;
procedure dfs(k,num:integer);
begin
  if num>c then exit;
  if num>ans then ans:=num;
  if k=n+1 then exit;
  dfs(k+1,num+w[k]);
  dfs(k+1,num);
end;
begin
  readln(c,n);
  for i:=1 to n do readln(w[i]);
  dfs(1,0);
  writeln(ans);
end.
