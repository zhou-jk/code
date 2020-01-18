var
  a,b,c,d:longint;
  e:real;
  f:boolean;
begin
  f:=false;
  repeat
    c:=c+1;
    readln(d);
    a:=a+300;
    a:=a-d;
    if a<0 then
      begin
        writeln('-',c);
        f:=true;
      end
    else
      begin
        b:=a div 100;
        a:=a-b*100;
        e:=e+b*100;
      end;
  until (c=12) or f;
  e:=e*1.2+a;
  if f=false then
    writeln(e:0:0);
  readln;
end.

