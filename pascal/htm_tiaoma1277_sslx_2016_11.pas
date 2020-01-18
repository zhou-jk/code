program htm_tiaoma1277_shensolianxi_2016_11_6;
const
  dy:array[1..4] of longint=(2,1,-1,-2);
  dx:array[1..4] of longint=(1,2,2,1);
var
  n,m,ans:longint;
procedure dfs(x,y:longint);
var i,tx,ty:longint;
begin
  if (x=m)and(y=n) then inc(ans);
  for i:=1 to 4 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx>=0)and(tx<=m)and(ty>=0)and(ty<=n) then dfs(tx,ty);
  end;
end;
begin
  readln(n,m);
  dfs(0,0);
  writeln(ans);
end.

