program htm_1034_xuanshu_dfs_2017_1_22;
var
  x:array[1..20] of longint;
  ans:longint;
  n,k,i:byte;
procedure dfs(a,b:byte;sum:longint);
var i:byte;
begin
  if a=k then
  begin
    for i:=2 to trunc(sqrt(sum)) do
      if sum mod i=0 then exit;
    //writeln(sum);
    inc(ans);
    exit;
  end;
  if n-b+1<k-a then exit;
  for i:=b to n do dfs(a+1,i+1,sum+x[i]);
end;
begin
  readln(n,k);
  for i:=1 to n do read(x[i]);
  dfs(0,1,0);
  writeln(ans);
end.
