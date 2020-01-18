program codevs_1065_01zifuchuan_dongtaiguihua_2017_1_20;
var
  f:array[0..30] of longint;
  n,i:integer;
begin
  readln(n);
  f[0]:=0; f[1]:=2; f[2]:=4;
  for i:=3 to n do f[i]:=f[i-1]+f[i-2];
  writeln(f[n]);
end.
