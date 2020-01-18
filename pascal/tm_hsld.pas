var
  a,b,c,pos,d:real;
function fc(x:real):real;
begin
  fc:=x*x*x*x*x-15*x*x*x*x+85*x*x*x-225*x*x+274*x-121;
end;
begin
  a:=1.5;
  b:=2.4;
  while b-a>1e-8 do
  begin
    c:=(a+b)/2;
    if fc(c)-0>=0 then
    begin a:=c+1e-8; pos:=c; end
    else  b:=c-1e-8;
    if abs(fc(pos-1e-7)-0)<abs(fc(pos)-0) then
      pos:=pos-1e-7;
  end;
  writeln(pos:0:6);
end.

