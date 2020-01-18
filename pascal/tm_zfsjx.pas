var
  a:char;
  b,c,d:longint;
begin
  c:=1;
  readln(a);
  for b:=1 to 3 do
    begin
      if b<>3 then
        write(' ':3-b);
      for d:=1 to c do
        begin
          write(a);
          if d=c then
            writeln;
        end;
      c:=c+2;
    end;
end.
