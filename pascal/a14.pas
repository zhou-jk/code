program a14;
var
  a,b,i,c,e,g:longint;
  d,f,h:boolean;
begin
  readln(a);
  b:=trunc(sqrt(a));
  d:=true;
  for i:=2 to b do
    if a mod i=0 then
      begin
        d:=false;
        f:=true;
        h:=true;
        for c:=2 to e do
          if i mod c=0 then
            f:=false;
         g:=a div i;
         e:=trunc(sqrt(g));
        for c:=2 to e do
          if g mod c=0 then
            h:=false;
        if f then
          writeln(i);
        if h then
          writeln(g);
      end;
  if d then
    writeln('yes')
  else
    writeln('no');
end.

