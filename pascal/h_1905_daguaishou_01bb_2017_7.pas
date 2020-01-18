program h_1905_daguaishou_01beibao_2017_7_22;
var
  s:array[0..10000] of boolean;
  n,i,j,a,sum:longint;
begin
  readln(n);
  s[0]:=true;
  for i:=1 to n do
  begin
    read(a);
    for j:=sum downto 0 do s[j+a]:=s[j+a]or s[j];
    sum:=sum+a;
  end;
  for i:=sum div 2 downto 0 do
    if s[i] then
    begin
      writeln(sqr(sum-i)-i*i);
      break;
    end;
end.

