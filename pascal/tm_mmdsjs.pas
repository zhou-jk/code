var
  a:array[1..100] of longint;
  b:array[1..1000] of boolean;
  n,i,j,c:longint;
begin
  readln(n);
  for i:=1 to n do
    if i=n then
      readln(a[i])
    else
      read(a[i]);
  for i:=1 to n do
    if b[a[i]]=false then
      begin
        b[a[i]]:=true;
        inc(j);
      end;
  writeln(j);
  for i:=1 to 1000 do
    if b[i] then
      begin
        write(i,' ');
        inc(c);
        if c=j then
          break;
      end;
  writeln;
  readln;
end.
