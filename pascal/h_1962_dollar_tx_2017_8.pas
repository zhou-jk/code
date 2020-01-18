program h_1962_dollar_tanxin_2017_8_5;
var
  a:array[1..101] of integer;
  n,i,t:integer;
  ans:real;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  i:=0; a[n+1]:=-maxint; ans:=100;
  while i<n do
  begin
    inc(i);
    while a[i]<a[i+1] do inc(i);
    t:=a[i];
    while (i<n)and(a[i+1]<=a[i]) do inc(i);
    ans:=ans*t/a[i];
  end;
  writeln(ans:0:2);
end.