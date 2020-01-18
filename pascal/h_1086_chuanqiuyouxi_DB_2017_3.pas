program h_1086_chuanqiuyouxi_DB_2017_3_4;
var
  f,g:array[1..30] of longint;
  n,m,i,j:byte;
begin
  readln(n,m);
  g[1]:=1;
  for i:=1 to m do
  begin
    f[1]:=g[n]+g[2];
    for j:=2 to n-1 do f[j]:=g[j-1]+g[j+1];
    f[n]:=g[n-1]+g[1];
    g:=f;
  end;
  writeln(f[1]);
end.
