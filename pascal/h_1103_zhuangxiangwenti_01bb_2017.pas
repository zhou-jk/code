program h_1103_zhuangxiangwenti_01beibao_2017_2_25;
var
  f:array[0..20000] of boolean;
  n,i,j,v,v1:integer;
begin
  readln(v);
  readln(n);
  f[0]:=true;
  for i:=1 to n do
  begin
    readln(v1);
    for j:=v downto v1 do f[j]:=f[j]or f[j-v1];
  end;
  for i:=v downto 0 do
    if f[i] then
    begin
      writeln(v-i);
      exit;
    end;
end.




