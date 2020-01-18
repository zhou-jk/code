program a18;
var
  a:char;
  b:integer;
begin
  readln(a);
  b:=ord(a);
  writeln(b);
  if b=107 then
    writeln('yes');
end.