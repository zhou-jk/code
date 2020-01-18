program htm_ziranshudehefengjie1265_shensolianxi_2016_11_1;
var
  n:integer;
  a:array[1..1000] of integer;
procedure dfs(m,j,k:integer);
var
  i:integer;
begin
  if (m=0)and(k>2) then
  begin
    for i:=1 to k-2 do write(a[i],'+');
    writeln(a[k-1]);
  end;
  for i:=j to m do
  begin
    a[k]:=i;
    dfs(m-i,i,k+1);
  end;
end;
begin
  readln(n);
  dfs(n,1,1);
end.