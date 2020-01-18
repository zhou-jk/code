program h_1873_paidui_2017_5_6;
var
  p,o:array[1..30000] of integer;
  n,i:integer;
function pd(a,b:byte):boolean;
begin
  pd:=false;
  if a<=6
  then if b>6
       then exit(true)
       else exit(a<b)
  else if a>=60 then
         if b<=6
         then

procedure sort(l,r:integer);
var  i,j,x,y:integer;
begin
  i:=l; j:=r; x:=o[(l+r) div 2];
  repeat
    while pd(o[i],x) do inc(i);
    while pd(x,o[j]) do dec(j);
    if i<=j then
    begin
      y:=p[i]; p[i]:=p[j]; p[j]:=y;
      y:=o[i]; o[i]:=o[j]; o[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n);
  for i:=1 to n do readln(p[i],o[i]);
  sort(1,n);
  for i:=1 to n do writeln(p[i]);
end.