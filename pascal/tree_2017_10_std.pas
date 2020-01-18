var
  g,f:array[1..100,1..100] of boolean;
  c:array[1..100] of longint;
  n,t,i,j,a:longint;
procedure max(var a:longint;b:longint);
begin
  if b>a then a:=b;
end;
begin
  assign(input,'tree.in'); assign(output,'tree.out');
  reset(input); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(c[i]);
    while not seekeof do
    begin
      read(t);
      g[i,t]:=true;
    end;
  end;
  fillchar(f,sizeof(f),127);
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        max(f[i,j],f[i,k]+f[k,j]);

  write(a);
  close(input); close(output);
end.