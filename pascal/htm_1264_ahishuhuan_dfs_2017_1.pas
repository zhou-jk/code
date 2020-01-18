program htm_1264_zhishuhuan_dfs_2017_1_22;
var
  b:array[1..31] of boolean;
  c:array[2..16] of boolean;
  a:array[1..16] of byte;
  n,i,j:byte;
procedure dfs(k:byte);
var i:byte;
begin
  if k=n+1 then
  begin
    if not b[a[n]+a[1]] then
    begin
      for i:=1 to n do write(a[i],' ');
      writeln;
    end;
    exit;
  end;
  for i:=2 to n do
    if not c[i]and not b[i+a[k-1]]  then
    begin
      c[i]:=true; a[k]:=i;
      dfs(k+1);
      c[i]:=false;
    end;
end;
begin
  readln(n);
  if n mod 2=1 then
  begin
    writeln(0);
    exit;
  end;
  for i:=2 to trunc(sqrt(2*n-1)) do
    for j:=2 to (2*n-1) div i do b[i*j]:=true;
  a[1]:=1;
  dfs(2);
end.

