var
  c:string;
  a:array[1..30] of longint;
  k,i,j,b,t:longint;
  d:boolean;
begin
  readln(c);
  for k:=2 to 9 do
    begin
      t:=0;
      j:=0;
      for i:=length(c) downto 1 do
        begin
          j:=j+1;
          val(c[i],a[j]);
        end;
      for i:=length(c) downto 1 do
         begin
           b:=a[i]+t*10;
           t:=b mod k;
         end;
      if t=0 then
        begin
          write(k,' ');
          d:=true;
        end;
    end;
  if d=false then
    writeln('none');
  readln;
end.



