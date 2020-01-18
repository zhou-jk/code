program h_1178_shuzizuhe_dongtaiguihua_2017_2_21;
var
  f:array[0..10000] of longint;
  a:array[1..100] of integer;
  n,m,i,j:integer;
begin
  readln(n,m);
  for i:=1 to n do read(a[i]);
  f[0]:=1;
  for i:=1 to n do
    for j:=m downto a[i] do inc(f[j],f[j-a[i]]);
  writeln(f[m]);
end.