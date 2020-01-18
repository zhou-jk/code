program noi_2_6_1775_caiyao_dongtaiguihua_2017_2_9;
var
  f:array[0..100,0..1000] of integer;
  w,v:array[1..100] of byte;
  t,m,i,j:integer;
begin
  readln(t,m);
  for i:=1 to m do
  begin
    readln(w[i],v[i]);
    for j:=1 to t do
    begin
      f[i,j]:=f[i-1,j];
      if (j>=w[i])and(f[i-1,j-w[i]]+v[i]>f[i,j]) then f[i,j]:=f[i-1,j-w[i]]+v[i];
    end;
  end;
  writeln(f[m,t]);
end.
