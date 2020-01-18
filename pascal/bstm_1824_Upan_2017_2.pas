program bstm_1824_Upan_2017_2_6;
var
  a:array[1..100] of integer;
  n,m,i,sum:longint;
procedure sort(l,r:longint);
var
  i,j,x,y:longint;
begin
  i:=l; j:=r; x:=a[(l+r) div 2];
  repeat
    while a[i]>x do inc(i);
    while x>a[j] do dec(j);
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n);
  readln(m);
  for i:=1 to n do readln(a[i]);
  sort(1,n);
  i:=0;
  while sum<m do
  begin
    inc(i);
    inc(sum,a[i]);
  end;
  writeln(i);
end.

