program h_1633_BESSIEdetizhongwenti_dongtaiguihua_2017_2_9;
var
  f:array[0..500,0..45000] of boolean;
  s:array[1..500] of word;
  h,n,i,j:word;
begin
  readln(h,n);
  for i:=0 to n do f[i,0]:=true;
  for i:=1 to n do
  begin
    readln(s[i]);
    for j:=1 to h do
    begin
      f[i,j]:=f[i-1,j];
      if (j>=s[i])and f[i-1,j-s[i]] then f[i,j]:=true;
    end;
  end;
  for i:=h downto 0 do
    if f[n,i] then
    begin
      writeln(i);
      break;
    end;
end.
