program codevs_migong1215_guanshuifa_2016_11_27;
const
  dx:array[1..4] of integer=(1,0,0,-1);
  dy:array[1..4] of integer=(0,1,-1,0);
var
  b:array[1..16,1..16] of boolean;
  a:array[1..16] of string[17];
  m,n,i,j:integer;
procedure dfs(x,y:integer);
var
  i,tx,ty:integer;
begin
  b[x,y]:=true;
  for i:=1 to 4 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx>0)and(tx<=n)and(ty>0)and(ty<=n)then
      if not b[tx,ty] and(a[tx][ty]<>'#')then
      begin
        b[tx,ty]:=true;
        dfs(tx,ty);
      end;
  end;
end;
begin
  readln(m);
  for i:=1 to m do
  begin
    readln(n);
    fillchar(b,sizeof(b),false);
    for j:=1 to n do readln(a[j]);
    dfs(1,1);
    if b[n,n]
    then writeln('YES')
    else writeln('NO');
  end;
end.

