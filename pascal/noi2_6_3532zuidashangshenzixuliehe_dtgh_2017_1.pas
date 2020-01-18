program noi2_6_3532zuidashangshenzixuliehe_dongtaiguihua_2017_1_21;
var
  b,f:array[1..1000] of longint;
  n,i,j:integer;
  ans:longint;
begin
  readln(n);
  for i:=1 to n do read(b[i]);
  f[1]:=b[1]; ans:=b[1];
  for i:=2 to n do
  begin
    for j:=1 to i-1 do
      if (b[j]<b[i])and(f[j]>f[i]) then f[i]:=f[j];
    inc(f[i],b[i]);
    if f[i]>ans then ans:=f[i];
  end;
  writeln(ans);
end.

