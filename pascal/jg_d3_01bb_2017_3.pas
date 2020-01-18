program jg_d3_01beibao_2017_3_4;
var
  f:array[0..1000] of integer;
  t,m,i,j,w,v:integer;
begin
  readln(t,m);
  for i:=1 to m do
  begin
    readln(w,v);
    for j:=t downto w do
      if f[j-w]+v>f[j] then f[j]:=f[j-w]+v;
  end;
  writeln(f[t]);
end.
