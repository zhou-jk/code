program noi_2_6_1996_dengshan_dongtaiguihua_2017_1_21;
var
  f1,f2,a:array[1..1000] of integer;
  n,i,j,ans:integer;
begin
  readln(n);
  if n<=0 then
  begin
    writeln(0);
    exit;
  end;
  read(a[1]); f1[1]:=1; f2[n]:=1;
  for i:=2 to n do read(a[i]);
  for i:=2 to n do
  begin
    for j:=1 to i-1 do
      if (a[j]<a[i])and(f1[j]>f1[i]) then f1[i]:=f1[j];
    inc(f1[i]);
  end;
  for i:=n-1 downto 1 do
  begin
    for j:=n downto i+1 do
      if (a[j]<a[i])and(f2[j]>f2[i]) then f2[i]:=f2[j];
    inc(f2[i]);
  end;
  for i:=1 to n do
    if f1[i]+f2[i]-1>ans then ans:=f1[i]+f2[i]-1;
  writeln(ans);
end.
