program htm_fangmu1025_shensolianxi_2016_11_13;
const
  f:array[1..4,1..2] of integer=((1,0),(-1,0),(0,1),(0,-1));
var
  k,i,x,y,ans:integer;
  a:array[1..5,1..5] of boolean;
procedure dfs(y,x:integer);
var
  i,j,tx,ty:integer;
begin
  if (y=5)and(x=5) then
  begin
    for i:=1 to 5 do
      for j:=1 to 5 do
        if a[i,j]=false then exit;
    inc(ans);
    exit;
  end;
  for i:=1 to 4 do
  begin
    ty:=y+f[i,1]; tx:=x+f[i,2];
    if (ty>5)or(ty<1)or(tx>5)or(tx<1)or a[ty,tx] then continue;
    a[ty,tx]:=true;
    dfs(ty,tx);
    a[ty,tx]:=false;
  end;
end;
begin
  readln(k);
  for i:=1 to k do
  begin
    readln(y,x);
    a[y,x]:=true;
  end;
  a[1,1]:=true;
  dfs(1,1);
  writeln(ans);
end.


