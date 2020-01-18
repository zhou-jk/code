program h_1976_fenshubijin_2017_8_7;
var
  p,n,i,t,t1,ax,ay,au,av:integer;
  s:extended;
begin
  readln(p,n);
  s:=sqrt(p); ax:=1; ay:=1; au:=n; av:=1;
  for i:=1 to n do
  begin
    t:=trunc(i*s)+1;
    while t/i>s do
    begin
      t1:=t;
      dec(t);
    end;
    if t>n then break;
    if s-t/i<s-ax/ay then
    begin
      ax:=t; ay:=i;
    end;
    if (t1<=n)and(t1/i-s<au/av-s) then
    begin
      au:=t1; av:=i;
    end;
  end;
  writeln(ax,'/',ay,' ',au,'/',av);
end.