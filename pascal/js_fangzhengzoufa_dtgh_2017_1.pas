program js_fangzhengzoufa_dongtaiguihua_2017_1_23;
var
  f:array[1..1000,1..1000] of int64;
  n,i,j:integer;
begin
  readln(n);
  for i:=1 to n do
  begin
    f[n,i]:=1;
    f[i,n]:=1;
  end;
  for i:=n-1 downto 1 do
    for j:=n-1 downto 1 do f[i,j]:=f[i+1,j]+f[i,j+1];
  writeln(f[1,1]);
end.
