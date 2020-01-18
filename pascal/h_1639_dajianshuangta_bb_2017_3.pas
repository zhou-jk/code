program h_1639_dajianshuangta_beibao_2017_3_5;
var
  f:array[0..2000,0..2000] of boolean;
  n,i,j,k,h,sum:integer;
begin
  readln(n);
  f[0,0]:=true;
  for i:=1 to n do
  begin
    read(h);
    inc(sum,h);
    for j:=sum downto 0 do
      for k:=sum downto 0 do
      begin
        if (j-h>=0)and(f[j-h,k]) then f[j,k]:=true;
        if (k-h>=0)and(f[j,k-h]) then f[j,k]:=true;
      end;
  end;
  for i:=sum div 2 downto 1 do
    if f[i,i] then
    begin
      writeln(i);
      exit;
    end;
  writeln('Impossible');
end.

