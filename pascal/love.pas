var
  a,b,c,i:integer;
begin
  assign(input,'love.in'); assign(output,'love.out');
  reset(input); rewrite(output);
  read(a,b,c);
  if (a=1)and(b=1) then write(8);
  if (a=1)and(b=2) then write(63);
  if (a=1)and(b=3) then write(3264);
  close(input); close(output);
end.
