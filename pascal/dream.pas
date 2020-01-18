const s:array[0..1] of string=('I love that ','I hate that ');
var n,i:byte;
begin
  assign(input,'dream.in'); assign(output,'dream.out');
  reset(input); rewrite(output);
  read(n);
  for i:=n downto 2 do write(s[i mod 2]);
  write('I hate it');
  close(input); close(output);
end.