var
  a:array[1..100000] of longint;
  b:array[1..10000] of longint;
  i,j,c,d,e,t,max:longint;
begin
  readln(c);
  b[1]:=1;
  a[1]:=b[1];
  e:=1;
  d:=1;
  for i:=2 to c do
    begin
      t:=0;
      for j:=1 to e do
        begin
          b[j]:=b[j]*i+t;
          t:=b[j] div 10;
          b[j]:=b[j] mod 10;
        end;
      while t>0 do
        begin
          inc(e);
          b[e]:=t mod 10;
          t:=t div 10;
        end;
      if d>e then
        max:=d
      else
        max:=e;
      for j:=1 to max do
        begin
          a[j]:=a[j]+b[j];
          a[j+1]:=a[j+1]+a[j] div 10;
          a[j]:=a[j] mod 10;
        end;
        d:=max;
        if a[j+1]>0 then
          inc(d);
    end;
  for i:=d downto 1 do
    write(a[i]);
  readln;
end.



