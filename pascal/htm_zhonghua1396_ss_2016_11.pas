program htm_zhonghua1396_shenso_2016_11_15;
var
  g:array[1..20,1..20] of boolean;
  g1:array[1..20] of integer;
  n,k,u,v,i:integer;
  ans:longint;
procedure dfs(t:integer);
var
  i,j:integer;
  b:boolean;
begin
  if t=n+1 then
  begin
    inc(ans);
    exit;
  end;
  for i:=1 to 4 do
  begin
    b:=false;
    for j:=1 to t-1 do
      if g[t,j]and(g1[j]=i) then begin b:=true; break; end;
    if b then continue;
    g1[t]:=i;
    dfs(t+1);
  end;
end;
begin
  readln(n,k);
  for i:=1 to k do
  begin
    readln(u,v);
    g[u,v]:=true;
    g[v,u]:=true;
  end;
  dfs(1);
  writeln(ans);
end.


