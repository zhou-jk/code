var
  c,f:array[1..2000,1..2000] of longint;
  n,m,x,y,i,j:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  assign(input,'color.in'); assign(output,'color.out');
  reset(input); rewrite(output);
  read(n,m,x,y);
  for i:=1 to n do
    for j:=1 to m do read(c[i,j]);
  for i:=x-1 downto 1 do f[i,y]:=f[i+1,y]+ord(c[i,y]<>c[i+1,y]);
  for i:=x+1 to m do f[i,y]:=f[i-1,y]+ord(c[i,y]<>c[i-1,y]);
  for i:=y-1 downto 1 do f[x,i]:=f[x,i+1]+ord(c[x,i]<>c[x,i+1]);
  for i:=y+1 to n do f[x,i]:=f[x,i-1]+ord(c[x,i]<>c[x,i-1]);
  for i:=x-1 downto 1 do
    for j:=y-1 downto 1 do f[i,j]:=min(f[i+1,j]+ord(c[i,j]<>c[i+1,j]),f[i,j+1]+ord(c[i,j]<>c[i,j+1]));
  for i:=x-1 downto 1 do
    for j:=y+1 to m do f[i,j]:=min(f[i+1,j]+ord(c[i,j]<>c[i+1,j]),f[i,j-1]+ord(c[i,j]<>c[i,j-1]));
  for i:=x+1 to n do
    for j:=y-1 downto 1 do f[i,j]:=min(f[i-1,j]+ord(c[i,j]<>c[i-1,j]),f[i,j+1]+ord(c[i,j]<>c[i,j+1]));
  for i:=x+1 to n do
    for j:=y+1 to n do f[i,j]:=min(f[i-1,j]+ord(c[i,j]<>c[i-1,j]),f[i,j-1]+ord(c[i,j]<>c[i,j-1]));
  for i:=1 to n do
  begin
    for j:=1 to m do write(f[i,j],' ');
    writeln;
  end;
  close(input); close(output);
end.

