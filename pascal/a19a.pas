program a19;
var
  a,p,q,r,s,j,k:string;
  b,l,m,t:longint;
  g,f:real;
  c:extended;
  d,o:boolean;
  e:char;
begin
  readln(a);
  p:='+';
  q:='-';
  r:='*';
  s:='/';
  l:=length(a);
  for b:=1 to l do
    if (a[b]=p) or (a[b]=q) or (a[b]=r) or (a[b]=s) then
      begin
        e:=a[b];
        m:=b-1;
        t:=l-b;
        j:=copy(a,1,m);
        k:=copy(a,b+1,t);
        break;
      end;
  val(j,g);
  val(k,f);
  d:=true;
  o:=false;
  case e of
    '+':c:=g+f;
    '-':c:=g-f;
    '*':c:=g*f;
    '/':if f<>0 then
          begin
            c:=g/f;
            o:=true;
          end
        else
          d:=false;
  end;
  if d=true then
    if o=true then
      writeln(c:0:100)
    else
      writeln(c:0:0)
  else
    writeln('Error!');
end.








