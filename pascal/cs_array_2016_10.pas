program cs_array_2016_10_16;
var
  a:array[1..100] of integer;
  i,j:integer;
begin
  for i:=1 to 100 do
    for j:=1to 100 do
      a[i][j]:=1;
  writeln(a[50][50]);
end.