program htm_1250_tuzidelvxing_dfs_2017_1_28;
type fx=array[1..4] of integer;
const
  dx:fx=(-1,1,0,0);
  dy:fx=(0,0,-1,1);
var
  a:array[1..200,1..200] of byte;
  n,b,i,ans,x:integer;
  y:char;
procedure dfs(x,y,f,s,k:integer);
var
  i,tx,ty:byte;
begin
  tx:=x+dx[f]; ty:=y+dy[f];
  if (tx<1)or(tx>n)or(ty<1)or(ty>n)or(a[tx,ty]=1) then
  begin
    if k=2 then
    begin
      if s>ans then ans:=s;
      exit;
    end;
    if f>2
    then begin
           dfs(x,y,1,s,2);
           dfs(x,y,2,s,2);
         end
    else begin
           dfs(x,y,3,s,2);
           dfs(x,y,4,s,2);
         end;
    exit;
  end;
  if a[tx,ty]=2 then
  begin
    //writeln('@');
    if s>ans then ans:=s;
    exit;
  end;
  a[x,y]:=2;
  dfs(tx,ty,f,s+1,1);
  a[x,y]:=0;
end;
begin
  readln(n,b);
  for i:=1 to b do
  begin
    readln(y,x);
    a[x,ord(y)-64]:=1;
  end;
  dfs(1,1,2,1,1);
  //writeln('!');
  dfs(1,1,4,1,1);
  writeln(ans);
end.
