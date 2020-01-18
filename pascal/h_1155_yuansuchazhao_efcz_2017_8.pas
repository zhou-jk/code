program h_1155_yuansuchazhao_erfenchazhao_2017_8_14;
var
  a:array[1..100000] of longint;
  n,m,t,i,l,r,mid:longint;
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
begin
  read(n,m);
  for i:=1 to n do read(a[i]);
  sort(1,n);
  for i:=1 to m do
  begin
    read(t);
    l:=1; r:=n;
    while l<=r do
    begin
      mid:=(l+r)div 2;
      if a[mid]=t then
      begin
        writeln('YES');
        break;
      end;
      if a[mid]>t
      then r:=mid-1
      else l:=mid+1;
    end;
    if a[mid]<>t then writeln('NO');
  end;
end.
