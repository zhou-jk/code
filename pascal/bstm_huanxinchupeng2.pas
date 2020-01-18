var
  ci:array[1..2000] of integer;
  n,i,j,a:longint;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(ci[i]);
    ci[i+n]:=ci[i];
  end;
  for i:=2*n downto n+1 do
    if ci[i]=0 then
      for j:=i-1 downto 1 do
        if ci[j]>1 then
        begin
          a:=a+sqr(i-j);
          dec(ci[j]);
          if j>n then dec(ci[j-n]);
          break;
        end;
  writeln(a);
end.