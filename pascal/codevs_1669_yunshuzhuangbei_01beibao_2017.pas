program codevs_1669_yunshuzhuangbei_01beibao_2017_2_19;
uses math;
var
  f:array[0..1000,0..1000] of longint;
  v,g,n,i,j,k,t,vi,gi:integer;
begin
  readln(v,g);
  readln(n);
  for i:=1 to n do
  begin
    readln(t,vi,gi);
    for j:=v downto vi do
      for k:=g downto gi do
        f[j,k]:=max(f[j,k],f[j-vi,k-gi]+t);
  end;
  writeln(f[v,g]);
end.
