program h_1201_233jishu_DB_2017_3_18;
var
  f:array[1..1000000] of longint;
  n,i,j:longint;
begin
  readln(n);
  f[3]:=1; f[4]:=1; f[5]:=1;
  for i:=6 to n do f[i]:=(((f[i-3]*2)mod 1000000007+f[i-4])mod 1000000007+f[i-5])mod 1000000007;
  writeln(f[n]);
end.
