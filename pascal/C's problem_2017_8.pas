//Tyvj 4811
var
  n,a,i:longint;
  s:qword;
begin
  read(n);
  for i:=1 to n do
  begin
    read(a);
    inc(s,a);
  end;
  write(s*s);
end.