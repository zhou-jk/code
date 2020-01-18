program codevs_2193shuzisanjiaoxingWW_dongtaiguihua_2016_12_30;
var
  a,b,c:array[1..25,0..25]of integer;
  n,i,j:integer;
function max(a,b:integer):integer;
begin
  if a>b then exit(a)
         else exit(b);
end;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to i do read(a[i,j]);
  b[1,1]:=a[1,1];
  for i:=2 to n div 2 do
    for j:=1 to i do b[i,j]:=max(b[i-1,j],b[i-1,j-1])+a[i,j];
  for i:=1 to n do c[n,i]:=a[n,i];
  for i:=n-1 downto n div 2 do
    for j:=n div 2 to i do c[i,j]:=max(c[i+1,j],c[i+1,j+1])+a[i,j];
  writeln(b[n div 2,n div 2]+c[n div 2,n div 2]-a[n div 2,n div 2]);
end.