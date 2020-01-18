var
  n,i,j,num:byte;
begin
  assign(input,'triangle.in'); assign(output,'triangle.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to i do
    begin
      inc(num);
      num:=num mod 10;
      write(num);
    end;
    writeln;
  end;
  close(input); close(output);
end.
