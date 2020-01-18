program codevs_2198shuzisanjiaoxingWWW_dongtaiguihua_2016_12_30;
var
  a,b,c:array[1..25,0..25]of integer;
  n,i,j,x,y:integer;
function max(a,b:integer):integer;
begin
  if a>b then exit(a)
         else exit(b);
end;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to i do read(a[i,j]);
  readln(x,y);
  b[1,1]:=a[1,1];
  for i:=2 to x do
    for j:=1 to i do b[i,j]:=max(b[i-1,j],b[i-1,j-1])+a[i,j];
  for i:=1 to n do c[n,i]:=a[n,i];
  for i:=n-1 downto x do
    for j:=y to n do c[i,j]:=max(c[i+1,j],c[i+1,j+1])+a[i,j];
  writeln(b[x,y]+c[x,y]-a[x,y]);
end.