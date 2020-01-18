program htm_1274_huiwenlujin_dfs_2017_1_23;
const
  dx:array[1..2] of byte=(1,0);
  dy:array[1..2] of byte=(0,1);
var
  s:array[1..100000] of string[35];
  a:array[1..18] of string[18];
  b:string[35];
  ans:integer;
  n,i,l:byte;
function p:boolean;
var i,j:byte;
begin
  i:=1; j:=l;
  p:=true;
  while i<j do
  begin
    if b[i]<>b[j] then exit(false);
    inc(i); dec(j);
  end;
end;
procedure dfs(x,y,k:byte);
var
  tx,ty:byte;
  i:integer;
begin
  b[k]:=a[x][y];
  //writeln('#',a[x][y],' ',b[k]);
  if (x=n)and(y=n) then
  begin
    //writeln('$',b,' ',length(b));
    if p then
    begin
      //writeln(b);
      for i:=1 to ans do
        if s[i]=b then exit;
      inc(ans);
      s[ans]:=b;
    end;
    exit;
  end;
  for i:=1 to 2 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx>0)and(tx<=n)and(ty>0)and(ty<=n) then dfs(tx,ty,k+1);
  end;
end;
begin
  readln(n);
  l:=2*n-1;
  b[0]:=chr(l);
  //b:='     ';
  for i:=1 to n do readln(a[i]);
  //for i:=1 to n do writeln(a[i]);
  dfs(1,1,1);
  writeln(ans);
end.
