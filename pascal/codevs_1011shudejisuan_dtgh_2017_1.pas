program codevs_1011shudejisuan_dongtaiguihua_2017_1_18;
var
  f:array[1..1000] of longint;
  n,i,j:integer;
begin
  readln(n);
  f[1]:=1;
  for i:=2 to n do
  begin
    f[i]:=1;
    for j:=1 to i div 2 do inc(f[i],f[j]);
  end;
  writeln(f[n]);
end.
