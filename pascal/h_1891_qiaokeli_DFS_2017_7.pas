program h_1891_qiaokeli_DFS_2017_7_18;
var
  f:array[0..30,0..30,0..50] of longint;
  t,n,m,k,i,j,p:integer;
  s:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  min:=b;
end;
procedure dfs(n,m,k:integer);
var i,j:integer;
begin
  if (f[n,m,k]<>s)or(k>m*n) then exit;
  if k=m*n then
  begin
    f[n,m,k]:=0;
	exit;
  end;
  for i:=1 to n div 2 do
    for j:=0 to k do
	begin
	  dfs(i,m,j); dfs(n-i,m,k-j);
	  f[n,m,k]:=min(f[n,m,k],f[i,m,j]+f[n-i,m,k-j]+m*m);
	end;
  for i:=1 to m div 2 do
	for j:=0 to k do
	begin
	  dfs(n,i,j); dfs(n,m-i,k-j);
	  f[n,m,k]:=min(f[n,m,k],f[n,i,j]+f[n,m-i,k-j]+n*n);
	end;
end;
begin
  readln(t);
  fillchar(f,sizeof(f),127); fillchar(s,sizeof(s),127);
  for i:=0 to 30 do
      for j:=0 to 30 do f[i,j,0]:=0;
  for i:=1 to t do
  begin
    readln(n,m,k);
    dfs(n,m,k);
    writeln(f[n,m,k]);
  end;
end.
