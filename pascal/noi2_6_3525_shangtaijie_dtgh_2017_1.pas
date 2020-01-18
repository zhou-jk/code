program noi2_6_3525_shangtaijie_dongtaiguihua_2017_1_21;
var
  f:array[1..100] of longint;
  n,i,b:byte;
begin
  readln(n);
  f[1]:=1; f[2]:=2; f[3]:=4; b:=3;
  while n>0 do
  begin
    for i:=b+1 to n do f[i]:=f[i-1]+f[i-2]+f[i-3];
    if n>b then b:=n;
    writeln(f[n]);
    readln(n);
  end;
end.