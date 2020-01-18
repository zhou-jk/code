program htm_1013_jihedehuafen_digui_2017_1_21;
var
  n,k:byte;
function f(a,b:byte):int64;
begin
  if (a<b)or(b=0) then exit(0);
  if (b=1)or(a=b) then exit(1);
  f:=f(a-1,b)*b+f(a-1,b-1);
end;
begin
  readln(n,k);
  writeln(f(n,k));
end.