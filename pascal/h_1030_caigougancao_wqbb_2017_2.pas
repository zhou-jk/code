program h_1030_caigougancao_wanquanbeibao_2017_2_21;
var
  f:array[0..55000] of longint;
  p,c:array[1..100] of integer;
  n,h,i,j,m,ans:longint;
begin
  readln(n,h);
  for i:=1 to n do
  begin
    readln(p[i],c[i]);
    if p[i]>m then m:=p[i];
  end;
  for i:=1 to h+m do f[i]:=1000000000;
  for i:=1 to n do
    for j:=p[i] to h+m do
      if f[j]>f[j-p[i]]+c[i] then f[j]:=f[j-p[i]]+c[i];
  ans:=f[h];
  for i:=h+1 to h+m do
    if f[i]<ans then ans:=f[i];
  writeln(ans);
end.
