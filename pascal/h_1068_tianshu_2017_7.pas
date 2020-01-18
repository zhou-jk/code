program h_1068_tianshu_2017_7_23;
const month:array[1..12] of integer=(31,28,31,30,31,30,31,31,30,31,30,31);
var y0,y,m0,m,d0,d,i,j,t:longint;
function pd(y:longint):boolean;
begin
  exit((y mod 4=0)and(y mod 100>0)or(y mod 400=0));
end;
function md(y,m,d:longint):longint;
var i:longint;
begin
  md:=0;
  for i:=1 to m-1 do md:=md+month[i];
  md:=md+d;
  if (m>2)and pd(y) then inc(md);
end;
begin
  readln(y0,m0,d0);
  readln(y,m,d);
  if (m0=2)and(d0=29)
  then y0:=y0+19*4
  else y0:=y0+19;
  t:=(y0-y)*365+md(y0,m0,d0);
  for i:=y to y0-1 do
    if pd(i) then inc(t);
  writeln(t-md(y,m,d));
end.
