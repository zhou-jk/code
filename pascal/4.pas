var
  a,b:array[1..50] of longint;
  n,k,i,j,t,c,o:longint;
begin
  a[1]:=1;
  c:=1;
  readln(n,k);
  for o:=1 to n do
    begin
      for i:=1 to n-k do
        begin
          for j:=1 to c do
           begin
              b[j]:=b[j]*k+t;
              t:=b[j] div 10;
              b[j]:=b[j] mod 10;
           end;
          while t>0 do
            begin
              inc(j);
              a[j]:=t mod 10;
              t:=t div 10;
             inc(c);
            end;
        end;
      for i:=1 to c do
        begin
          a[i]:=a[i]+b[i];
          a[i+1]:=a[i+1]+a[i] div 10;
          a[i]:=a[i] mod 10;
        end;
    end;
  for i:=1 to 50 do
    if a[i]<>0 then
      c:=i;
  for i:=c downto 1 do
    write(a[i]);
  readln;
end.