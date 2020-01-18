program htm_1720_oujilidedeyouxi_2017_1_31;
var
  c,m,n,i,t:longint;
  f:boolean;
begin
  readln(c);
  for i:=1 to c do
  begin
    readln(m,n);
    if m<n then
    begin
      inc(m,n);
      n:=m-n;
      dec(m,n);
    end;
    f:=true;
    while (m div n=1)and(m mod n>0) do
    begin
      t:=m mod n; m:=n; n:=t;
      f:=not f;
    end;
    if f
    then writeln('Stan wins')
    else writeln('Ollie wins');
  end;
end.




