program test_input_2017_7_30;
var
  a:array[1..10000] of longint;
  n,i:longint;
begin
  readln(n);
  if n>10 then
  begin
    writeln(n);
    exit;
  end;
  for i:=1 to n do read(a[i]);
end.