program test_2011_6;
type arr=array[1..10000] of longint;
var
  a,b:arr;
  i,j,m,c,s,sum:longint;
  procedure swap(var x,y:longint);
  var
    t:longint;
  begin
    t:=x;x:=y;y:=t;
  end;
begin
  readln(m,s,c); sum:=0;
  if m>c then writeln(c) else
  begin
  for i:=1 to c do
    readln(a[i]);
  for i:=1 to c-1 do
    for j:=c downto i+1 do
      if a[j-1]>a[j] then swap(a[j-1],a[j]);
  j:=1;
  for i:=1 to c-1 do
  begin
    b[j]:=a[i+1]-a[i];
    j:=j+1;
  end;
  for i:=1 to c-2 do
    for j:=c-1 downto i+1 do
      if b[j-1]>b[j] then swap(b[j-1],b[j]);
  for j:=1 to c-m do
  begin
    sum:=sum+b[j];
  end;
  writeln(sum+c-m);
  end;
end.