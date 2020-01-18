program bstm_1825_luobozichuan_2017_2_7_yh;
var
  co,cx,mo,mx,min,max,m:longint;
function mi(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  while not eof do
  begin
    readln(co,cx,mo,mx);
    if (mo=0)or(co=0) then
    begin
      writeln(mi(mx,cx));
      continue;
    end;
    if (mx=0)or(cx=0) then
    begin
      writeln(mi(mo,co));
      continue;
    end;
    if co>cx
    then begin
           min:=cx;
	   max:=co;
	   m:=mo;
	 end
    else begin
           min:=co;
	   max:=cx;
	   m:=mx;
         end;
    if (min+1)*m>=max
    then writeln(cx+co)
    else writeln(min+(min+1)*m);
  end;
end.
