program htm_1225_shijinzhizhuanhuaweibajinzhi_digui_2017_1_23;
var
  n:integer;
procedure f(a:integer);
begin
  if a=0 then exit;
  f(a div 8);
  write(a mod 8);
end;
begin
  readln(n);
  f(n);
end.
