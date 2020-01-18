program htm_1263_zuhedeshuchu_2017_1_25;
var
  a:array[1..20] of byte;
  n,k:byte;
procedure dfs(t,t1:byte);
var i:byte;
begin
  if t=k then
  begin
    for i:=1 to k do write(a[i]:3);
    writeln;
    exit;
  end;
  if t1=n+1 then exit;
  a[t+1]:=t1;
  dfs(t+1,t1+1);
  dfs(t,t1+1);
end;
begin
  readln(n,k);
  dfs(0,1);
end.