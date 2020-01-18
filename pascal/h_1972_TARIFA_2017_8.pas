program h_1972_TARIFA_2017_8_7;
var
  x,n,p,i,ans:integer;
begin
  readln(x);
  readln(n);
  for i:=1 to n do
  begin
    readln(p);
    inc(ans,x-p);
  end;
  writeln(ans+x);
end.