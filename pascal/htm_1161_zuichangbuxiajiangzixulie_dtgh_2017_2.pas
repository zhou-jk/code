program htm_1161_zuichangbuxiajiangzixulie_dongtaiguihua_2017_2_5;
var
  a,f:array[1..100000] of longint;
  n,i,j,ans:longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
  begin
    for j:=1 to i-1 do
      if (a[j]<=a[i])and(f[j]>f[i]) then f[i]:=f[j];
    inc(f[i]);
    if f[i]>ans then ans:=f[i];
  end;
  writeln(ans);
end.