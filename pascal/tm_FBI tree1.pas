var
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
  readln(g);
  readln(h);
  k:=FBI(1,length(h),h);
  writeln(k);
end.








