program htm_1262_quanpailei_dfs_2017_1_22;
var
  a:array[1..10] of byte;
  b:array[1..10] of boolean;
  n:byte;
procedure dfs(k:byte);
var i:byte;
begin
  if k=n+1 then
  begin
    for i:=1 to n do write(a[i]:5);
    writeln;
    exit;
  end;
  for i:=1 to n do
    if not b[i] then
    begin
      b[i]:=true; a[k]:=i;
      dfs(k+1);
      b[i]:=false;
    end;
end;
begin
  readln(n);
  dfs(1);
end.