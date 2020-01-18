program test_char_2017_7_12;
type str=array[1..2] of char;
var
  a,b:str;
begin
  a:='ab';
  b:='ac';
  writeln(a,' ',b,' ',a>b);
  readln(a);
  writeln(a);
end.
