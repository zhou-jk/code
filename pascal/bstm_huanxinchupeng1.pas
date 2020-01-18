var
  ri:array[1..1000] of integer;
  n,i,j,a,b:longint;
begin
  readln(n);
  for i:=1 to n do
    readln(ri[i]);
  a:=100000000;
  for i:=1 to n do
  begin
    b:=0;
    for j:=1 to i-1 do
      b:=b+(j+n-i)*ri[j];
    for j:=i+1 to n do
      b:=b+(j-i)*ri[j];
    if b<a then a:=b;
  end;
  writeln(a);
end.
