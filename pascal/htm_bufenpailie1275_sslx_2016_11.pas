program htm_bufenpailie1275_shensolianxi_2016_11_5;
var
  n,r:integer;
  a:array[1..9] of integer;
  b:array[1..9] of boolean;
procedure dfs(k:integer);
var
  i:integer;
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
