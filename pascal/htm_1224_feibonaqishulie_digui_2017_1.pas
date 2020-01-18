program htm_1224_feibonaqishulie_digui_2017_1_23;
var
  n:byte;
function f(a:byte):longint;
begin
  if a=1 then exit(0);
  if (a=2)or(a=3) then exit(1);
  f:=f(a-1)+f(a-2);
end;
begin
  readln(n);
  if n=0 then begin writeln(0); exit; end;
  writeln(f(n));
end.

