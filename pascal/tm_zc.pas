var
  a,b,c:longint;
begin
  readln(a);
  b:=3;
  repeat
    if a mod b=0 then
      begin
        write(b,' ');
        c:=c+1;
      end;
    b:=b+2;
  until b>7;
  if c=0 then
    writeln('n');
  readln;
end.