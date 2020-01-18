program noi_2_6_1944_chitangguo_dongtaiguihua_2017_2_9;
var
  f:array[1..20] of longint;
  n,i:byte;
begin
  readln(n);
  f[1]:=1; f[2]:=2;
  for i:=3 to n do f[i]:=f[i-1]+f[i-2];
  writeln(f[n]);
end.