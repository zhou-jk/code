program h_1938_zuijinjuli_2017_7_30;
var
  x,y:array[1..2000] of longint;
  n,i,j,l,r:longint;
  m:real;
begin
  readln(n);
  m:=maxlongint;
  for i:=1 to n do
  begin
    readln(x[i],y[i]);
    for j:=1 to i-1 do
      if sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))<m then
      begin
        m:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
        l:=j; r:=i;
      end;
  end;
  writeln(l,' ',r);
end.
