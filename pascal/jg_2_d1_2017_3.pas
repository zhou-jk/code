program jg_2_d1_2017_3_18;
var
  b,a:array[1..5001]of integer;
  n,m,i,j,t:integer;
procedure sort(l,r:integer);
var i,j,x,y:integer;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while x<a[i] do inc(i);
    while x>a[j] do dec(j);
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      y:=b[i]; b[i]:=b[j]; b[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
procedure sort1(l,r:integer);
var i,j,x,y:integer;
begin
  i:=l; j:=r; x:=b[(l+r)div 2];
  repeat
    while x>b[i] do inc(i);
    while x<b[j] do dec(j);
    if i<=j then
    begin
      y:=b[i]; b[i]:=b[j]; b[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort1(l,j);
  if i<r then sort1(i,r);
end;
begin
  readln(n,m);
  for i:=1 to n do readln(b[i],a[i]);
  sort(1,n);
  m:=trunc(m*1.5); t:=a[m]; j:=1; a[n+1]:=-maxint;
  for i:=1 to n do
  begin
    if a[i]<t then break;
    //writeln(a[i],' ',a[i+1]);
    if a[i]<>a[i+1] then
    begin
      //writeln('#',j,' ',i);
      sort1(j,i);
      j:=i+1;
    end;
  end;
  if a[i]<t then dec(i);
  writeln(t,' ',i);
  for j:=1 to i do writeln(b[j],' ',a[j]);
end.
