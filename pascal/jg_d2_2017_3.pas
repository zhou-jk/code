program jg_d2_2017_3_10;
var
  b:array[1..1000] of boolean;
  n,m,i,num:integer;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(num);
    if not b[num] then
    begin
      inc(m);
      b[num]:=true;
    end;
  end;
  writeln(m);
  for i:=1 to 1000 do
    if b[i] then write(i,' ');
end.



