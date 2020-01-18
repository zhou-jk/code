var
  a,b,c:array[1..200] of longint;
  i,j,f:longint;
  d,e:string;
begin
  readln(d);
  readln(e);
  for i:=length(d) downto 1 do
    begin
      j:=j+1;
      val(d[i],b[j]);
    end;
  j:=0;
  for i:=length(e) downto 1 do
    begin
      j:=j+1;
      val(e[i],c[j]);
    end;
  for i:=1 to 200 do
    begin
      a[i]:=b[i]-c[i];
      if a[i]<0 then
        begin
          b[i+1]:=b[i+1]-1;
          a[i]:=a[i]+10;
        end;
    end;
  for i:=1 to 200 do
    if a[i]<>0 then
      f:=i;
  for i:=f downto 1 do
    write(a[i]);
  readln;
end.