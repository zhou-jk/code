//tyvj 4810
var
  n,a,i,c:integer;
begin
  read(n);
  for i:=1 to n do
  begin
    read(a);
    if a mod 2=1 then inc(c);
  end;
  write(c);
end.