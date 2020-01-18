program htm_1226_qiuN_digui_2017_1_23;
var
  n:integer;
function f(a:integer):int64;
begin
  if a=0 then exit(1);
  f:=f(a-1)*a;
end;
begin
  readln(n);
  writeln(n,'!=',f(n));
end.