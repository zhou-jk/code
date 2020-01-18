program htm_1027_tiaoqi_dfs_2017_1_25;
type ar=array[1..4] of integer;
const
  dx:ar=(-1,1,1,-1);
  dy:ar=(1,1,-1,-1);
var
  s,w:array[1..1000,1..2] of byte;
  a:array[1..30] of string;
  n,i,j,m,an:integer;
  b:boolean;
procedure dfs(x,y,k,t:integer);
var i,tx,ty:integer;
begin
  s[k,1]:=x; s[k,2]:=y;
  if t=m then
  begin
    for i:=1 to k do writeln(s[i,1],' ',s[i,2]);
    halt;
  end;
  a[x,y]:='*';
  for i:=1 to 4 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx>0)and(tx<=n)and(ty>0)and(ty<=n)and(a[tx,ty]='o') then
    begin
      a[tx,ty]:='+';
      tx:=tx+dx[i]; ty:=ty+dy[i];
      if (tx>0)and(tx<=n)and(ty>0)and(ty<=n)and(a[tx,ty]='+') then dfs(tx,ty,k+1,t+1);
      tx:=x+dx[i]; ty:=y+dy[i];
      a[tx,ty]:='o';
    end;
  end;
  a[x,y]:='+';
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(a[i]);
    for j:=1 to n do
    begin
      if a[i][j]='o' then inc(m);
      if a[i][j]='K' then
      begin
        inc(an);
        w[an,1]:=i; w[an,2]:=j;
      end;
    end;
  end;
  for i:=1 to an do dfs(w[i,1],w[i,2],1,0);
  writeln('impossible');
end.



