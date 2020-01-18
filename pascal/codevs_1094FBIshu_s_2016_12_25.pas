program codevs_1094FBIshu_shu_2016_12_25;
var
  g,i:integer;
  h:ansistring;
function FBI(a,b:integer):ansistring;
var
  e,f:boolean;
begin
  if b-a=0 then
    case h[b] of
      '0':exit('B');
      '1':exit('I');
    end;
  FBI:=FBI(a,(b-a+1)div 2+a-1)+FBI(b-(b-a+1)div 2+1,b);
  e:=true;
  f:=true;
  for i:=a to b do
    case h[i] of
      '0':e:=false;
      '1':f:=false;
    end;
  if e
  then FBI:=FBI+'I'
  else if f
       then FBI:=FBI+'B'
       else FBI:=FBI+'F';
end;
begin
  readln(g);
  readln(h);
  writeln(FBI(1,length(h)));
end.
