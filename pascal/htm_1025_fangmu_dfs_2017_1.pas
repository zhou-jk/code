
program htm_1025_fangmu_dfs_2017_1_23;

const 
  dx: array[1..4] of integer = (-1,0,1,0);
  dy: array[1..4] of integer = (0,1,0,-1);
var 
  a: array[1..5,1..5] of boolean;
  k,i,x,y: byte;
  ans: longint;
procedure dfs(x,y:byte);
var i,j,tx,ty: byte;
begin
  if (x=5)and(y=5) then
  begin
    for i:=1 to 5 do
      for j:=1 to 5 do
        if not a[i,j] then exit;
    inc(ans);
    exit;
  end;
  for i:=1 to 4 do
  begin
    tx := x+dx[i];
    ty := y+dy[i];
    if (tx>0)and(tx<6)and(ty>0)and(ty<6)and not a[tx,ty] then
    begin
      a[tx,ty] := true;
      dfs(tx,ty);
      a[tx,ty] := false;
    end;
  end;
end;
begin
  readln(k);
  for i:=1 to k do
  begin
    readln(x,y);
    a[x,y] := true;
  end;
  a[1,1] := true;
  dfs(1,1);
  writeln(ans);
end.
