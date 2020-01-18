program htm_1196_shuzisanjiaoxin2_db_2017_2_4;
var
  f:array[1..25,1..25,0..99] of boolean;
  a:array[1..25,1..25] of integer;
  n,i,j,k,t:byte;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to i do read(a[i,j]);
  for i:=1 to n do f[n,i,a[n,i]]:=true;
  for i:=n-1 downto 1 do
    for j:=1 to i do
      for k:=0 to 99 do
      begin
        t:=((k-a[i,j])mod 100+100)mod 100;
        f[i,j,k]:=f[i+1,j,t]or f[i+1,j+1,t];
      end;
  for i:=99 downto 0 do
    if f[1,1,i] then
    begin
      writeln(i);
      exit;
    end;
end.

