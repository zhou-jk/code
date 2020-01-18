program codevs_1219_qishiyouli_dongtaiguihua_2017_1_20;
var
  f:array[-1..52,1..50] of int64;
  n,m,x1,y1,x2,y2,i,j:integer;
begin
  readln(n,m);
  readln(x1,y1,x2,y2);
  f[y2,x2]:=1;
  //writeln('#');
  for i:=x2-1 downto x1 do
    for j:=m downto 1 do {begin} f[j,i]:=f[j+2,i+1]+f[j-2,i+1]+f[j+1,i+2]+f[j-1,i+2]; {writeln(i,j); end;}
  writeln(f[y1,x1]);
end.

