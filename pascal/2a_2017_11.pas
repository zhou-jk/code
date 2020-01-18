//PrayerOJ 2073
var
  q:array[-100..100,-100..100] of char;
  n,x,y,i,j,x1,x2,y1,y2:integer;
procedure min(var a:integer;b:integer);
begin
  if b<a then a:=b;
end;
procedure max(var a:integer;b:integer);
begin
  if b>a then a:=b;
end;
begin
  read(n);
  fillchar(q,sizeof(q),'.'); fillchar(q[0],sizeof(q[0]),'-');
  for i:=-100 to 100 do q[i,0]:='|';
  q[0,0]:='+';
  for i:=1 to n do
  begin
    read(x,y);
    q[y,x]:='*';
    min(x1,x); max(x2,x); min(y1,y); max(y2,y);
  end;
  for i:=y2 downto y1 do
  begin
    for j:=x1 to x2 do write(q[i,j]);
    writeln;
  end;
end.