program h_1950_heweigeidingshu_erfenchazhao_2017_8_15;
var
  num:array[1..100000] of longint;
  n,m,i,t,l,r,mid:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=num[(l+r)div 2];
  repeat
    while num[i]<x do inc(i);
    while x<num[j] do dec(j);
    if i<=j then
    begin
      y:=num[i]; num[i]:=num[j]; num[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  read(n);
  for i:=1 to n do read(num[i]);
  sort(1,n);
  read(m);
  for i:=1 to n-1 do
  begin
    l:=i+1; r:=n; t:=m-num[i];
    while l<=r do
    begin
      mid:=(l+r)div 2;
      if num[mid]=t then
      begin
        writeln(num[i],' ',t);
        exit;
      end;
      if num[mid]>t
      then r:=mid-1
      else l:=mid+1;
    end;
  end;
  write('No');
end.
