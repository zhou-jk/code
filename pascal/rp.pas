var
  a,an:array[1..100] of string;
  m,i,j,sum,max,num1,t:integer;
  num,n:string;
  c:char;
procedure sort(l,r:longint);
var
  i,j:longint;
  x,y:string;
begin
  i:=l; j:=r; x:=an[(l+r) div 2];
  repeat
    while an[i]<x do inc(i);
    while x<an[j] do dec(j);
    if i<=j then
    begin
      y:=an[i]; an[i]:=an[j]; an[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  assign(input,'rp.in'); assign(output,'rp.out');
  reset(input); rewrite(output);
  while not seekeof do
  begin
    inc(m);
    readln(a[m]);
  end;
  max:=-maxint;
  for i:=1 to m do
  begin
    j:=1;
    n:='';
    while a[i,j]<>':' do
    begin
      n:=n+a[i,j];
      inc(j);
    end;
    inc(j);
    c:='+';
    sum:=0;
    while j<=length(a[i]) do
    begin
      num:='';
      while (a[i,j]>='0')and(a[i,j]<='9') do
      begin
        num:=num+a[i,j];
        inc(j);
      end;
      val(num,num1);
      if c='+'
      then inc(sum,num1)
      else dec(sum,num1);
      c:=a[i,j];
      inc(j);
    end;
    if sum=max then
    begin
      inc(t);
      an[t]:=n;
    end;
    if sum>max then
    begin
      t:=1;
      an[1]:=n;
      max:=sum;
    end;
  end;
  sort(1,t);
  for i:=1 to t do writeln(an[i]);
  close(input); close(output);
end.



