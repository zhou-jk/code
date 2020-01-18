program noi2_6_1759zuichangshangshenzixulie_dongtaiguihua_2017_1_6;
var
  d,f:array[1..1000] of integer;
  n,i,j:integer;
  ans:longint;
begin
  readln(n);
  for i:=1 to n do read(d[i]);
  f[1]:=1;
  for i:=2 to n do
  begin
    for j:=1 to i-1 do
      if (d[j]<d[i])and(f[j]>f[i]) then f[i]:=f[j];
    inc(f[i]);
  end;
  ans:=f[1];
  for i:=2 to n do if f[i]>ans then ans:=f[i];
  writeln(ans);
end.

