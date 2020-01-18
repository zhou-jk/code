program htm_migongwenti1282_shensolianxi_2016_10_30;
const f:array[1..8,1..2] of integer=((-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1));
var
  n,i,j:integer;
  ans:longint;
  a:array[1..10,1..10] of integer;
  b:array[1..10,1..10] of boolean;
procedure ss(x,y:integer);
var
  i,x1,y1:integer;
begin
  if (x=1)and(y=n) then
  begin
    inc(ans);
    exit;
  end;
  b[x,y]:=true;
  for i:=1 to 8 do
  begin
    x1:=x+f[i,1]; y1:=y+f[i,2];
    if (x1>0)and(x1<=n)and(y1>0)and(y1<=n) then
      if not b[x1,y1] then
        if a[x1,y1]=0 then ss(x1,y1);
  end;
  b[x,y]:=false;
end;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
      read(a[i,j]);
  ss(1,1);
  writeln(ans);
end.


