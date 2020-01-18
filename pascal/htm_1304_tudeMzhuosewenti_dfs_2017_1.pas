program htm_1304_tudeMzhuosewenti_dfs_2017_1_25;
var
  g:array[1..20,1..20] of boolean;
  g1:array[1..20] of integer;
  n,k,m,u,v,i:integer;
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
  for i:=1 to m do
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
  readln(n,k,m);
  for i:=1 to k do
  begin
    readln(u,v);
    g[u,v]:=true;
    g[v,u]:=true;
  end;
  g1[1]:=1;
  dfs(2);
  writeln(ans*m);
end.


