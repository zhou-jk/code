program codevs_1220_shuzisanjiaoxing_dongtaiguihua_2016_12_30;
var
  a,b:array[1..100,1..100]of integer;
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
  for i:=1 to n do b[n,i]:=a[n,i];
  for i:=n-1 downto 1 do
    for j:=1 to i do b[i,j]:=max(b[i+1,j],b[i+1,j+1])+a[i,j];
  writeln(b[1,1]);
end.
