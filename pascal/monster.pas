var
  s:array[0..10000] of boolean;
  n,i,j,a,sum:longint;
begin
  assign(input,'monster.in'); assign(output,'monster.out');
  reset(input); rewrite(output);
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
  close(input); close(output);
end.




