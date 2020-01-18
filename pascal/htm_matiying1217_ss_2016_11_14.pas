program htm_matiying1217_shenso_2016_11_14;
const
  dy:array[1..4] of integer=(1,0,0,-1);
  dx:array[1..4] of integer=(0,1,-1,0);
var
  n,i,j,ans:integer;
  a:array[1..5,1..5] of char;
  b:array[1..5,1..5] of boolean;
procedure dfs(y,x,l,r:integer);
var
  i,ty,tx:integer;
begin
  //writeln(y,' ',x);
  b[y,x]:=true;
  if a[y,x]='('
  then inc(l)
  else inc(r);
  if l=r then
  begin
    if l+r>ans then ans:=l+r;
    b[y,x]:=false;
    exit;
  end;
  for i:=1 to 4 do
  begin
    ty:=y+dy[i]; tx:=x+dx[i];
    if (ty<1)or(ty>n)or(tx<1)or(tx>n)or b[ty,tx] then continue;
    if (a[ty,tx]='(')and(a[y,x]=')') then continue;
    dfs(ty,tx,l,r);
  end;
  b[y,x]:=false;
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n-1 do read(a[i,j]);
    readln(a[i,n]);
  end;
  {for i:=1 to n do
  begin
    for j:=1 to n-1 do write(a[i,j]);
    writeln(a[i,n]);
  end;}
  dfs(1,1,0,0);
  writeln(ans);
end.
