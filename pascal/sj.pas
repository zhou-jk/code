program sj;
var
  a:array[1..10,1..10] of longint;
  i,j:longint;
begin
  a[1,1]:=1;
  for i:=2 to 10 do
    begin
      a[i,1]:=1;
      a[i,i]:=1;
      if i>2 then
        for j:=2 to i-1 do
          a[i,j]:=a[i-1,j-1]+a[i-1,j];
    end;
  for i:=1 to 10 do
    begin
      if i<>10 then
        write(' ':30-3*i);
      for j:=1 to i do
        write(a[i,j]:6);
      writeln;
    end;
end.


