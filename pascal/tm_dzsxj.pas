var
  a,d,e:array[1..201] of longint;
  i,f,g,j:longint;
  b,c:string;
begin
  readln(b);
  readln(c);
  for i:=length(b) downto 1 do
    begin
      j:=j+1;
      val(b[i],d[j]);
    end;
  j:=0;
  for i:=length(c) downto 1 do
    begin
      j:=j+1;
      val(c[i],e[j]);
    end;
  for i:=1 to 200 do
    begin
      g:=d[i]+e[i];
      a[i]:=a[i]+g;
      a[i+1]:=a[i] div 10;
      a[i]:=a[i] mod 10;
    end;
  for i:=1 to 201 do
    if a[i]<>0 then
      f:=i;
  for i:=f downto 2 do
    write(a[i]);
  writeln(a[1]);
  readln;
end.


