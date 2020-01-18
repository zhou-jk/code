program htm_1282_migongwenti_dfs_2017_1_22;
const
  dx:array[1..8] of integer=(-1,-1,0,1,1,1,0,-1);
  dy:array[1..8] of integer=(0,1,1,1,0,-1,-1,-1);
var
  a:array[1..10,1..10] of byte;
  ans:longint;
  n,i,j:byte;
procedure dfs(x,y:byte);
var i,tx,ty:byte;
begin
  if (x=1)and(y=n) then
  begin
    inc(ans);
    exit;
  end;
  a[x,y]:=1;
  for i:=1 to 8 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx>0)and(tx<=n)and(ty>0)and(ty<=n)and(a[tx,ty]=0) then dfs(tx,ty);
  end;
  a[x,y]:=0;
end;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  dfs(1,1);
  writeln(ans);
end.

