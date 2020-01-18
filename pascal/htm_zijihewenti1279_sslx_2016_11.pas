program htm_zijihewenti1279_shensolianxi_2016_11_27;
var
  s:array[1..20] of integer;
  n,c,i:integer;
  ans:longint;
procedure dfs(k,num:longint);
begin
  if num=c then inc(ans);
  if (k=n+1)or(num>=c) then exit;
  dfs(k+1,num+s[k]);
  dfs(k+1,num);
end;
begin
  readln(n,c);
  for i:=1 to n do read(s[i]);
  dfs(1,0);
  writeln(ans);
end.