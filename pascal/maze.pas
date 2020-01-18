const
  dx:array[1..4]of integer=(-1,1,0,0);
  dy:array[1..4]of integer=(0,0,-1,1);
var
  b:array[1..33,1..33]of boolean;
  m:array[1..33]of string;
  n,i,ans,j:longint;
procedure dfs(x,y:byte);
var i,tx,ty:byte;
begin
  b[x,y]:=true;
  for i:=1 to 4 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx<1)or(ty<1)or(tx>n)or(ty>n)or(m[tx,ty]='#') then
    begin
      inc(ans);
      continue;
    end;
    if not b[tx,ty] then dfs(tx,ty);
  end;
end;
begin
  assign(input,'maze.in'); assign(output,'maze.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do readln(m[i]);
  dfs(1,1);
  if not b[n,n] then dfs(n,n);
  writeln(ans*9-36);
  close(input); close(output);
end.
