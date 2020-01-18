program h_1947_xingqiwu_2017_8_1;
var
  m:array[1..12] of longint=(31,28,31,30,31,30,31,31,30,31,30,31);
  a:array[0..6] of longint;
  n,i,j,d:longint;
begin
  readln(n);
  d:=1;
  {if n=1 //wrong
  then begin
         inc(m[1]); //m[d]
         for i:=1 to 11 do
         begin
           d:=(d+m[i])mod 7;
           inc(a[d]);
         end;
       end
  else for i:=1 to n-2 do
         for j:=12 downto 1 do
         begin
           d:=m[j]-d;
           if (j=2)and(((n-i)mod 4=0)and((n-i)mod 100<>0)or((n-i)mod 400=0)) then inc(d);
           d:=((d div 7+1)*7-d)mod 7;
           inc(a[d]);
         end;}
  for i:=0 to n-1 do
    for j:=1 to 12 do
    begin
      inc(a[d]);
      if (j=2)and(((1900+i)mod 4=0)and((1900+i)mod 100<>0)or((1900+i)mod 400=0)) then inc(d);
      d:=(d+m[j])mod 7;
    end;
  for i:=1 to 6 do write(a[i],' ');
  writeln(a[0]);
end.