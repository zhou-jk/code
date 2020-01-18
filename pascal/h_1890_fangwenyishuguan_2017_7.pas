program h_1890_fangwenyishuguan_2017_7_10;
const
  dx:array[1..4] of longint=(-1,1,0,0);
  dy:array[1..4] of longint=(0,0,-1,1);
var
  b:array[1..1000,1..1000] of longint;
  g:array[1..1000,1..1000] of char;
  c:array[1..100000] of longint;
  n,m,k,x,y,i,j:longint;
procedure dfs(x,y:longint);
var j,tx,ty:longint;
begin
  b[x,y]:=i;
  for j:=1 to 4 do
  begin
    tx:=x+dx[j];
    ty:=y+dy[j];
    if g[tx,ty]='*' then
    begin
      inc(c[i]);
      continue;
    end;
    if b[tx,ty]=0 then dfs(tx,ty);
  end;
end;
begin
  readln(n,m,k);
  for i:=1 to n do
  begin
    for j:=1 to m do read(g[i,j]);
    readln;
  end;
  for i:=1 to k do
  begin
    readln(x,y);
    if b[x,y]>0 then
    begin
      writeln(c[b[x,y]]);
      continue;
    end;
    dfs(x,y);
    writeln(c[i]);
  end;
end.






