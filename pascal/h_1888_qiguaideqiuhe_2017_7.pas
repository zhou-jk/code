program h_1888_qiguaideqiuhe_2017_7_10;
var
  t,i,m:longint;
  n,a:int64;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(n);
    m:=1;
    a:=(1+n)*n div 2;
    while m<=n do
    begin
      m:=m shl 1;
      a:=a-m;
    end;
    writeln(a);
  end;
end.

