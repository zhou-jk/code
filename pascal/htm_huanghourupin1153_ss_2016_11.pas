program htm_huanghourupin1153_sosuo_2016_11_27;
var
  c_:array[1..8] of integer;
  n,c,i:integer;
  ans:longint;
procedure dfs(ied,num:integer);
var
  i:integer;
begin
  if num=n then inc(ans);
  if num>=n then exit;
  for i:=ied to c do dfs(i,num+c_[i]);
end;
begin
  readln(n,c);
  for i:=1 to c do readln(c_[i]);
  dfs(1,0);
  writeln(ans);
end.
