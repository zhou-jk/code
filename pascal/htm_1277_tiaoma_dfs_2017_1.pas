program htm_1277_tiaoma_dfs_2017_1_23;
const
  dx:array[1..4] of integer=(2,1,-1,-2);
  dy:array[1..4] of integer=(1,2,2,1);
var
  n,m:integer;
  ans:longint;
procedure dfs(x,y:integer);
var
  tx,ty:integer;
  i:byte;
begin
  if (x=n)and(y=m) then
  begin
    inc(ans);
    exit;
  end;
  for i:=1 to 4 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx>-1)and(tx<=n)and(ty>-1)and(ty<=m) then dfs(tx,ty);
  end;
end;
begin
  readln(n,m);
  dfs(0,0);
  writeln(ans);
end.
