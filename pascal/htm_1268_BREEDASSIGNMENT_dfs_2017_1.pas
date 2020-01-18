program htm_1268_BreedAssignment_dfs_2017_1_23;
var
  b:array[1..15,1..15] of char;
  a:array[1..15] of byte;
  n,m,i,x,y:byte;
  ans:longint;
  s:char;
function p(k,o:byte):boolean;
var j:byte;
begin
  p:=true;
  for j:=1 to k-1 do
  begin
    if b[k,j]='S'then
      if a[j]<>o then exit(false);
    if b[k,j]='D' then
      if a[j]=o then exit(false);
  end;
end;
procedure dfs(k:byte);
var i,j:byte;
begin
  if k=n+1 then
  begin
    inc(ans);
    exit;
  end;
  for i:=1 to 3 do
    if p(k,i) then
    begin
      a[k]:=i;
      dfs(k+1);
    end;
  end;
begin
  readln(n,m);
  for i:=1 to m do
  begin
    readln(s,x,y);
    b[x,y]:=s;
    b[y,x]:=s;
  end;
  a[1]:=1;
  dfs(2);
  writeln(ans*3);
end.


