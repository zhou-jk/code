program htm_1769_kuaisumi_2017_1_30;
var
  m,n,k,i,m1,s:longint;
begin
  readln(m,n,k);
  m1:=m mod k;
  s:=m1;
  for i:=2 to n do
  begin
    s:=s*m1;
    s:=s mod k;
  end;
  writeln(s);
end.
