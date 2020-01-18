program htm_1275_bufenpailie_dfs_2017_1_31;
var
   b:array[1..9] of boolean;
  a:array[1..9] of byte;
  n,r:byte;
procedure dfs(k:byte);
var i:byte;
begin
  if k=r+1 then
  begin
    for i:=1 to r do write(a[i]:3);
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
  readln(n,r);
  dfs(1);
end.