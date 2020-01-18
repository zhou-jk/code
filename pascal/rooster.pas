var g1,g2,k,a,b,x,y,i:longint;
procedure stop(o:longint);
begin
  write(o);
  close(input); close(output);
  halt;
end;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  assign(input,'rooster.in'); assign(output,'rooster.out');
  reset(input); rewrite(output);
  read(g1,g2,k);
  if g1=g2 then stop(0);
  for i:=1 to k do
  begin
    read(a,x,b,y);
    g1:=max(g1+a*x,0); g2:=max(g2+b*y,0);
    if g1=g2 then stop(i);
  end;
  stop(-1);
  close(input); close(output);
end.
