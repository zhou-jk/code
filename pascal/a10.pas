program a10;
var
  a,b,c,d,e:integer;
begin
  readln(a);
  if a>=100 then
    begin
      b:=a div 100;  c:=a div 10-b*10;  d:=a-c*10-b*100;
    end;
  if (a>=10) and (a<100) then
    begin
      b:=a div 10;  c:=a-b*10;
    end;
  if a>100 then writeln('3',' ',b,'*100',' ',c,'*10',' ',d);
  if (a>=10) and (a<100) then writeln('2',' ',b,'*10',' ',c);
  if (a<10) and (a>0) then writeln('1',' ',a);
  if (a<=0) or (a>=1000) then writeln('no!');
end.
