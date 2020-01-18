var
  a:array['a'..'z'] of longint;
  b:ansistring;
  i:longint;
  c:boolean;
begin
  readln(b);
  for i:=1 to length(b) do
    inc(a[b[i]]);
  for i:=1 to length(b) do
    if a[b[i]]=1 then
      begin
        writeln(b[i]);
        c:=true;
        break;
      end;
  if c=false then
    writeln('no');
  readln;
end.