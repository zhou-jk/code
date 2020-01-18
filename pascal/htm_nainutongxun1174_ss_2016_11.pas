program htm_nainutongxun1174_shenso_2016_11_27;
var
  n,i,j,ans:integer;
  a:array[1..12] of integer;
  b:array[1..12,1..3] of integer;
  c:array[1..12] of boolean;
procedure dfs(k:integer);
var
  i,j,mi:integer;
begin
  if k=n+1 then
  begin
    mi:=0;
    for i:=1 to n do
      for j:=1 to 3 do
        inc(mi,abs(a[b[i,j]]-a[i]));
    mi:=mi div 2;
    if mi<ans then ans:=mi;
    exit;
  end;
  for i:=1 to n do
    if not c[i] then
    begin
      c[i]:=true; a[k]:=i;
      dfs(k+1);
      c[i]:=false;
    end;
end;
begin
  readln(n);
  ans:=10000;
  for i:=1 to n do
    for j:=1 to 3 do
      read(b[i,j]);
  dfs(1);
  writeln(ans);
end.
