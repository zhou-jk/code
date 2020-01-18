program a19;
var
  a,e,p,q,r,s:string;
  b,f,h,i,l,m,n:longint;
  j,k:real;
  c:extended;
  d,g,o:boolean;
begin
  readln(a);
  h:=0;
  i:=0;
  p:='+';
  q:='-';
  r:='*';
  s:='/';
  l:=length(a);
  for b:=1 to length(a) do
    if (a[b]=p) or (a[b]=q) or (a[b]=r) or (a[b]=s) then
      begin
        h:=h+1;
        if h>=2 then
          g:=true
        else
          begin
            e:=a[b];
            m:=b-1;
            n:=b+1;
            j:=copy(a,1,m);
            k:=copy(a,n,l);
          end;
      end
    else
      for f:=0 to 9 do
        if a[b]<>f then
          g:=true
        else i:=i+1;
  if g or (i=length(a)) then
    begin
      e:='no';
      writeln('Error!');
    end;
  d:=true;
  o:=false;
  case e of
    '+':c:=j+k;
    '-':c:=j-k;
    '*':c:=j*k;
    '/':if k<>0 then
          begin
            c:=j/k;
            o:=true;
          end
        else
          d:=false;
  if d then
    if o then
      writeln(c:0:6);
    else
      writeln(c:0:0);
end.
      writeln(c:0:100)
    else
      writeln(c)
  else
    writeln('Error!');
end.








