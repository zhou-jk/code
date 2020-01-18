var
  a,b:ansistring;
  i,t:longint;
  c:real;
begin
  readln(c);
  readln(a);
  readln(b);
  for i:=1 to length(a) do
    if a[i]=b[i] then
      inc(t);
  if c<=t/length(a) then
    writeln('yes')
  else
    writeln('no');
  readln;
end.