program htm_1227_shuangseHANOIwenti_digui_2017_1_22;
var
  c:array[1..3,1..100] of integer;
  n:integer;
procedure move(a,b,c:char;n:integer);
begin
  if n=1 then begin writeln(n,' ',a,' ',b); exit; end;
  move(a,c,b,n-1);
  writeln(n,' ',a,' ',b);
  move(c,b,a,n-1);
end;
begin
  readln(n);
  move('A','B','C',n);
end.
