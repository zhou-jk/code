program jg_codevs_2193_shuzisanjiaoxingWW_dfs_2017_4_30;
var
  a:array[1..25,0..25]of integer;
  n,i,j:integer;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  max:=b;
end;
function dfs(x,y:byte):integer;
begin
  if (x<1)or(y<1) then exit(-maxint);
  if (x=1)and(y=1) then exit(a[1,1]);
  dfs:=max(dfs(x-1,y),dfs(x-1,y-1))+a[x,y];
end;
function dfs1(x,y:byte):integer;
begin
  if (x>n)or(y>n) then exit(-maxint);
  if x=n then exit(a[n,y]);
  dfs1:=max(dfs1(x+1,y),dfs1(x+1,y+1))+a[x,y];
end;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to i do read(a[i,j]);
  writeln(dfs(n div 2,n div 2)+dfs1(n div 2,n div 2)-a[n div 2,n div 2]);
end.
