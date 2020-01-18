program htm_1256_erdemicifang_digui_2017_1_21;
var
  n:int64;
procedure f(n:int64);
var i:longint;
begin
  if n=0 then begin write(0); exit; end;
  if n=2 then begin write(2); exit; end;
  while n>0 do
  begin
    i:=trunc(ln(n)/ln(2));
    n:=n-round(exp(i*ln(2)));
    if i=1
    then write(2)
    else begin
           write('2(');
           f(i);
           write(')');
         end;
    if n>0 then write('+');
  end;
end;
begin
  readln(n);
  f(n);
end.
