program h_1433_tuzijiapushu_DB_2017_4_2_V1;
var
  f:array[0..100,0..200]of longint;
  n,k,i,j,p:byte;
begin
  readln(n,k);
  for i:=1 to k do f[i,1]:=1;
  for i:=1 to k do
    for j:=2 to n do
      for p:=1 to j-2 do f[i,j]:=(f[i,j]+f[i-1,p]*f[i-1,j-1-p])mod 9901;
  writeln(((f[k,n]-f[k-1,n])mod 9901+9901)mod 9901);
end.
