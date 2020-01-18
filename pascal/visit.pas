const
  dx:array[1..4] of integer=(-1,0,1,0);
  dy:array[1..4] of integer=(0,-1,0,1);
var
  b:array[1..1000,1..1000] of boolean;
  a:array[1..1000,1..1000] of char;
  n,m,k,x,y,i,j,ans:longint;
procedure dfs(x,y:integer);
var i,tx,ty:integer;
begin
  b[x,y]:=true;
  for i:=1 to 4 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx<1)or(tx>n)or(ty<1)or(ty>m)or b[tx,ty] then continue;
    if a[tx,ty]='*' then
    begin
      inc(ans);
      continue;
    end;
    dfs(tx,ty);
  end;
end;
begin
  assign(input,'visit.in'); assign(output,'visit.out');
  reset(input); rewrite(output);
  readln(n,m,k);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  for i:=1 to k do
  begin
    readln(x,y);
    fillchar(b,sizeof(b),false);
    ans:=0;
    dfs(x,y);
    writeln(ans);
  end;
  close(input); close(output);
end.
