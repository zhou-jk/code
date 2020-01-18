program a23;
var
  a,b,c:longint;
begin
  randomize;
  a:=random(101);
  c:=0;
  repeat
    readln(b);
    c:=c+1;
    if b>a then
      writeln('Too big.');
    if b<a then
      writeln('Too small.');
  until b=a;
  writeln('Flt.',' ',c,' ',a);
end.
