program htm_huanghourupin1153_sosuo_2016_11_27_hls;
var
  c_:array[1..8] of integer;
  n,c,i:integer;
  ans:longint;
procedure dfs(k,num:integer);
var
  i:integer;
begin
  if num=n then inc(ans);
  if (num=n)or(k>c) then exit;
  for i:=0 to (n-num)div c_[k] do dfs(k+1,num+i*c_[k]);
end;
begin
  readln(n,c);
  for i:=1 to c do readln(c_[i]);
  dfs(1,0);
  writeln(ans);
end.
