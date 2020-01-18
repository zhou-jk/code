program xh;
var
  a,b:longint;
  c,d:ansistring;
  f1:text;
begin
  randomize;
  assign(f1,'d:\xh.out');
  rewrite(f1);
  repeat
    a:=random(2);
    Str(a,d);
    write(f1,d);
    b:=b+1;
    write(a);
  until b=1000000;
  close(f1);
end.
