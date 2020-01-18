program h_1078_wadilei_zuichangshangshenzixulie_2017_3_13;
var
  a:array[1..100,1..101] of byte;
  f:array[1..100] of longint;
  w:array[1..100] of integer;
  n,i,j,ans:longint;
begin
  readln(n);
  for i:=1 to n do read(w[i]);
  for i:=1 to n do
    for j:=i to n do read(a[i,j]);
  for i:=n downto 1 do
  begin
    for j:=i+1 to n do
      if (a[i,j]=1)and(f[j]>f[i]) then f[i]:=f[j];
    inc(f[i],w[i]);
    if f[i]>ans then ans:=f[i];
  end;
  writeln(ans);
end.



