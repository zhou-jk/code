program htm_chuanquyouxi1086_shenso_2016_11_9;
var
  n,m,i,j,ans:longint;
  a:array[1..30,1..30] of longint;
function dfs(k,p:longint):longint;
var
  b,c:longint;
begin
  dfs:=0;
  if k=m then
  begin
    if (p=n)or(p=2) then dfs:=1;
    exit;
  end;
  if a[k,p]<>-1 then exit(a[k,p]);
  if p=1
  then b:=dfs(k+1,n)
  else b:=dfs(K+1,p-1);
  if p=n
  then c:=dfs(k+1,1)
  else c:=dfs(k+1,p+1);
  dfs:=b+c;
  a[k,p]:=dfs;
end;
begin
  for i:=1 to 30 do
    for j:=1 to 30 do
      a[i,j]:=-1;
  readln(n,m);
  writeln(dfs(1,1));
end.
