var
  a:longint;
  b:boolean;
begin
  readln(a);
  b:=true;
  if a mod 4<>0 then
    b:=false;
  if a mod 100=0 then
    if (a mod 400<>0) or (a mod 3200=0) then
      b:=false;
  if b then
    writeln('Y')
  else
    writeln('N');
end.
