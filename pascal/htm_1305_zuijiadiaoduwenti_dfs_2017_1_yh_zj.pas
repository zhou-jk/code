program htm_1305_zuijiadiaoduwenti_dfs_2017_1_25_yh_zj;
var
  var
  t:array[1..17] of longint;
  a:array[1..5] of longint;
  n,k,ans,i:longint;
begin
  readln(n,k);
  for i:=1 to n do read(t[i]);
  ans:=10000;
  dfs(1,0);
  writeln(ans);
end.