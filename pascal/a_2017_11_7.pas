var
  l,i,a:longint;
  s:ansistring;
begin
  assign(input,'a.in'); assign(output,'a.out');
  reset(input); rewrite(output);
  read(s);
  s:=upcase(s);
  for i:=1 to length(s)-3 do
    if (s[i]='W')and(s[i+1]='H')and(s[i+2]='O')and(s[i+3]='I') then inc(a);
  write(a);
  close(input); close(output);
end.