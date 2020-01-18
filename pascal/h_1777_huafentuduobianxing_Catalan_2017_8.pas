program h_1777_huafentuduobianxing_Catalan_2017_8_2;
var
  f:array[1..18] of longint;
  n,i,j:byte;
begin
  readln(n);
  if n<3 then
  begin
    writeln('No answer');
    exit;
  end;
  f[2]:=1;
  for i:=3 to n do
    for j:=2 to i-1 do
      f[i]:=f[i]+f[j]*f[i-j+1];
  writeln(f[n]);
end.




