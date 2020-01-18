program a14;
var
  a,b,i,c:longint;
  d:boolean;
begin
  readln(a);
  b:=trunc(sqrt(a));
  d:=true;
  for i:=2 to b do
    if a mod i=0 then
      begin
        d:=false;
        c:=a div i;
        writeln(i,' ',c);
      end;
  if d then
    writeln('yes')
  else
    writeln('no');
end.

