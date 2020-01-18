program codevs_zuijialvcao1569_guanshui_2016_12_4;
const
  dx:array[1..4] of integer=(1,0,0,-1);
  dy:array[1..4] of integer=(0,1,-1,0);
var
  m:array[1..100] of string[100];
  b:array[1..100,1..100] of boolean;
  r,c,i,j,ans:integer;
  d:boolean;
procedure dfs(x,y:integer);
var
  i,tx,ty:integer;
begin
  b[x,y]:=true;
  inc(ans);
  for i:=1 to 4 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx>0)and(tx<=c)and(ty>0)and(ty<=r)and not b[tx,ty] and(m[tx][ty]='.') then dfs(tx,ty);
  end;
end;
begin
  readln(r,c);
  while (r<>0)or(c<>0) do
  begin
    for i:=1 to c do readln(m[i]);
    ans:=0; d:=false;
    for i:=1 to c do
    begin
      for j:=1 to r do
        if not b[i,j] and(m[i][j]='@') then
        begin
          dfs(i,j);
          d:=true;
          break;
        end;
      if d then break;
    end;
    for i:=1 to c do
      for j:=1 to r do b[i,j]:=false;
    writeln(ans);
    readln(r,c);
  end;
end.

