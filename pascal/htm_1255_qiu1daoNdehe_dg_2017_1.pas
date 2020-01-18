program htm_1255_qiu1daoNdehe_digui_2017_1_23;
var
  n:integer;
function f(a:integer):longint;
begin
  if a=1 then exit(1);
  f:=f(a-1)+a;
end;
begin
  readln(n);
  writeln(f(n));
end.