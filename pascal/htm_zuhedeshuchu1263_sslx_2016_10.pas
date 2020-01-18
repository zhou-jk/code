program htm_zuhedeshuchu1263_shensolianxi_2016_10_31;
var
  n,k,c:integer;
  b:array[1..19] of integer;
procedure dfs(t,s,a:integer);
var
  i:integer;
begin
  if (t=n+2)or(s=k+1) then exit;
  if a<>0 then b[s]:=a;
  if s=k then begin for i:=1 to k do write(b[i]:3); writeln; exit; end;
  dfs(t+1,s+1,t);
  dfs(t+1,s,0);
end;
begin
  readln(n,k);
  dfs(1,0,0);
end.
