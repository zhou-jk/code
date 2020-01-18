program htm_1017_gongzuofenpei_dfs_2017_1_23;
var
  a:array[1..20,1..20] of integer;
  b:array[1..20] of boolean;
  ans:integer;
  n,i,j:byte;
procedure dfs(k:byte;sum:integer);
var i:byte;
begin
  if sum>=ans then exit;
  if k=n+1 then
  begin
    ans:=sum;
    exit;
  end;
  for i:=1 to n do
    if not b[i] then
    begin
      b[i]:=true;
      dfs(k+1,sum+a[k,i]);
      b[i]:=false;
    end;
end;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  ans:=maxint;
  dfs(1,0);
  writeln(ans);
end.

