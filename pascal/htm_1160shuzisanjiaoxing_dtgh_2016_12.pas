program htm_1160shuzisanjiaoxing_dongtaiguihua_2016_12_25;
var
  a,f:array[1..24,1..24] of integer;
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
  for i:=1 to n do f[n,i]:=a[n,i];
  for i:=n-1 downto 1 do
    for j:=1 to i do
      f[i,j]:=max(f[i+1,j],f[i+1,j+1])+a[i,j];
  writeln(f[1,1]);
end.

