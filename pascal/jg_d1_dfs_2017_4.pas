program jg_d1_dfs_2017_4_22;
const
  dx:array[1..8] of integer=(-1,-1,0,1,1,1,0,-1);
  dy:array[1..8] of integer=(0,1,1,1,0,-1,-1,-1);
var
  b:array[1..10000,1..10000] of boolean;
  f:array[1..10000,1..10000] of byte;
  n,i,j,x1,y1,x2,y2:integer;
procedure dfs(x,y:integer);
var i,tx,ty:integer;
begin
  if f[x,y]=0 then exit;
  b[x,y]:=true;
  for i:=1 to 8 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx>0)and(tx<=n)and(ty>0)and(ty<=n)and not b[tx,ty] then dfs(tx,ty);
  end;
end;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do read(f[i,j]);
  readln(x1,y1);
  readln(x2,y2);
  dfs(x1,y1);
  if b[x2,y2]
  then writeln(1)
  else writeln(-1);
end.

