var
  a:ansistring;
  i,j,t,b:longint;
begin
  readln(a);
  a:=' '+a+' ';
  for i:=1 to length(a)-2 do
    if a[i]=' ' then
      begin
        j:=1;
        t:=0;
        while a[i+j]<>' ' do
          begin
            t:=t+1;
            j:=j+1;
          end;
        if t<>0 then
          begin
            b:=b+1;
            if b=1 then
              write(t)
            else
              write(',',t);
          end;
      end;
  readln;
end.
