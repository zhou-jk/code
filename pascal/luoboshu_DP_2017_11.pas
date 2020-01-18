//PrayerOJ 1908
var
  g:array[1..1000,1..1000] of integer;
  f:array[1..1000,0..1] of integer;
  m:array[1..1000] of integer;
  n,k,i,j,a:integer;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  exit(b);
end;
function dfs(k,c:integer):integer;
var i,s:integer;
begin
  if f[k,c]>-1 then exit(f[k,c]);
  f[k,c]:=0; s:=0;
  for i:=1 to m[k] do inc(s,max(dfs(g[k,i],1),dfs(g[k,i],0)));
  if c=1
  then for i:=1 to m[k] do f[k,c]:=max(f[k,c],s-max(f[g[k,i],0],f[g[k,i],1])+f[g[k,i],0]+1)
  else f[k,c]:=s;
  exit(f[k,c]);
end;
begin
  read(n);
  for i:=1 to n do
  begin
    read(k,m[k]);
    for j:=1 to m[k] do read(g[k,j]);
  end;
  fillchar(f,4000,255);
  for i:=1 to n do a:=max(a,max(dfs(i,1),dfs(i,0)));
  write(a);
end.
