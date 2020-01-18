var
  x,y,z,o:char;
  n:longint;
procedure move(n:longint;a,c,b:char);
begin
  if n=0 then exit;
  move(n-1,a,b,c);
  writeln(a,'->',n,'->',c);
  move(n-1,b,c,a);
end;
begin
  readln(n,o,x,o,y,o,z);
  move(n,x,z,y);
end.
