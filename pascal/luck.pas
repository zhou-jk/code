var n:longint;
begin
  assign(input,'luck.in'); assign(output,'luck.out');
  reset(input); rewrite(output);
  read(n);
  write(n div 2+(n div 3+1)div 2);
  close(input); close(output);
end.