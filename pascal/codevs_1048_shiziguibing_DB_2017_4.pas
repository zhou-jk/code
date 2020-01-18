program codevs_1048_shiziguibing_DB_2017_4_2;
var
  f,su:array[0..100,0..100]of longint;
  w:array[1..100]of integer;
  n,i,j,k:byte;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  min:=b;
end;
begin
  readln(n);
  for i:=1 to n do read(w[i]);
  for i:=1 to n do
    for j:=i to n do su[i,j]:=su[i,j-1]+w[j];
  for i:=n downto 1 do
    for j:=i+1 to n do
    begin
      f[i,j]:=maxlongint;
      for k:=i to j-1 do f[i,j]:=min(f[i,j],f[i,k]+f[k+1,j]+su[i,j]);
    end;
  writeln(f[1,n]);
end.
