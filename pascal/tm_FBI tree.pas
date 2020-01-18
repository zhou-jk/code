var
  f1,f2:text;
  g,i:longint;
  h,k:string;
function FBI(a,b:longint;c:string):string;
var
  d:char;
  e,f:boolean;
begin
  if b-a=0 then
  begin
    d:=c[b];
    case d of
      '0':FBI:='B';
      '1':FBI:='I';
    end;
  end
  else
  begin
    e:=true;
    f:=true;
    FBI:=FBI(a,(b+a) div 2,c)+FBI((a+b) div 2+1,b,c);
    for i:=a to b do
      case c[i] of
        '0':e:=false;
        '1':f:=false;
      end;
    if e
    then FBI:=FBI+'I'
    else if f
         then FBI:=FBI+'B'
         else FBI:=FBI+'F';
  end;
end;
begin
  assign(f1,'fbi.in');
  assign(f2,'fbi.out');
  reset(f1);
  readln(f1,g);
  readln(f1,h);
  close(f1);
  k:=FBI(1,g*2,h);
  rewrite(f2);
  write(f2,k);
  close(f2);
end.








