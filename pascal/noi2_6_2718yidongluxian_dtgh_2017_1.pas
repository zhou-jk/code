program noi2_6_2718yidongluxian_dongtaiguihua_2017_1_1;
var
  a:array[1..20,1..20] of longint;
  m,n,i,j:integer;
begin
  readln(m,n);
  for i:=1 to m do
    for j:=1 to n do a[i,j]:=1;
  for i:=m-1 downto 1 do
    for j:=n-1 downto 1 do a[i,j]:=a[i+1,j]+a[i,j+1];
  writeln(a[1,1]);
end.