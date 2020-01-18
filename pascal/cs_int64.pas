var
  a:array[1..255] of longint;
  n,i,j,b,e,f:longint;
  d,g:boolean;
begin
  d:=false;
  readln(n);
  if n<>1 then
    begin
      b:=2*2;
      a[1]:=b;
      if n>2 then
        for i:=3 to n do
          begin
            g:=true;
            for e:=1 to 255 do
              if a[e]<>0 then
                f:=e;
                //writeln('###t
                for j:=1 to f do
                  if g=true then
                    begin
                      b:=a[j];
                      b:=b*2;
                      if d=true then
                        begin
                          b:=b+1;
                          d:=false;
                        end;
                      if b>=10 then
                        begin
                          d:=true;
                          if a[j+1]=0 then
                            begin
                              a[j+1]:=1; d:=false; g:=false;
                            end;
                        end;
                      b:=b mod 10; a[j]:=b;
                    end
                  else
                    g:=true;
          end;
    end
  else
    a[1]:=2;
  for e:=1 to 255 do
    if a[e]<>0 then
      f:=e;
  for e:=f downto 1 do
    write(a[e]);
  readln;
end.



