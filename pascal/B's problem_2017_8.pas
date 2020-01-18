//Tyvj 4745
var
  a:array[1..100] of byte;
  n,i,n25,n50:byte;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
procedure no;
begin
  write('NO');
  halt;
end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  sort(1,n);
  for i:=1 to n do
    case a[i] of
      25:inc(n25);
      50:begin
           if n25=0 then no;
           dec(n25); inc(n50);
         end;
      100:begin
            if (n25>0)and(n50>0)
            then begin
                   dec(n25); dec(n50);
                 end
            else if n25>=3
                 then dec(n25,3)
                 else no;
          end;
    end;
  write('YES');
end.