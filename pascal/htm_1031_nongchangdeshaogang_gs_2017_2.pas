program htm_1031_nongchangdeshaogang_guanshui_2017_2_3;
type ar=array[1..8] of integer;
const
  dx:ar=(-1,-1,0,1,1,1,0,-1);
  dy:ar=(0,1,1,1,0,-1,-1,-1);
var
  h:array[1..700,1..700] of integer;
  b:array[1..700,1..700] of boolean;
  n,m,ans,s,i,j:longint;
procedure dfs(x,y:integer);
var i,tx,ty:integer;
begin
  b[x,y]:=true;
  for i:=1 to 8 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx<1)or(tx>n)or(ty<1)or(ty>m) then continue;
    if h[tx,ty]>h[x,y] then s:=0;
    if (h[tx,ty]<>h[x,y])or b[tx,ty] then continue;
    dfs(tx,ty);
  end;
end;
begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do read(h[i,j]);
  for i:=1 to n do
    for j:=1 to m do
      if not b[i,j] then
      begin
        s:=1;
        dfs(i,j);
        inc(ans,s);
      end;
  writeln(ans);
end.


