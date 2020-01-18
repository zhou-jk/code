var
  a:array[1..50000] of longint;
  b,i,j,t,e,c:longint;
begin
  c:=10000;
  readln(b);
  if b>1 then
    begin
      a[1]:=1;
      e:=1;
      for i:=2 to b do
        begin
          for j:=1 to e do
            begin
              a[j]:=a[j]*i+t;
              t:=a[j] div c;
              a[j]:=a[j] mod c;
            end;
          while t>0 do
            begin
              e:=e+1;
              a[e]:=t;
              t:=a[e] div c;
              a[e]:=a[e] mod c;
            end;
        end;
      write(a[e]);
      for i:=e-1 downto 1 do
        begin
          if a[i]<10 then
            write('000',a[i])
          else
            if a[i]<100 then
              write('00',a[i])
            else
              if a[i]<1000 then
               write('0',a[i])
              else
                write(a[i]);
        end;
    end
  else
    writeln('1');
  readln;
end.
