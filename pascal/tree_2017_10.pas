var 
  g: array[1..100,0..100] of byte;
  c,f: array[1..100] of longint;
  n,i,j,a: longint;
procedure max(var a:longint;b:longint);
begin
  if b>a then a := b;
end;
begin
  assign(input,'tree.in');
  assign(output,'tree.out');
  reset(input);
  rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(c[i]);
    while not seekeof do
    begin
      inc(g[i,0]);
      read(g[i,g[i,0]]);
    end;
  end;
  for i:=n downto 1 do
  begin
    for j:=1 to g[i,0] do
      max(f[i],g[i,j]);
    inc(f[i],c[i]);
    max(a,f[i]);
  end;
  write(a);
  close(input);
  close(output);
end.
