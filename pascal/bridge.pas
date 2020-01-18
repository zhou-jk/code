var
  t:array[1..1000] of longint;
  n,i,a:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=t[(l+r)div 2];
  repeat
    while t[i]<x do inc(i);
    while x<t[j] do dec(j);
    if i<=j then
    begin
      y:=t[i]; t[i]:=t[j]; t[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  assign(input,'bridge.in'); assign(output,'bridge.out');
  reset(input); rewrite(output);
  read(n);
  for i:=1 to n do read(t[i]);
  sort(1,n);
  a:=t[2];
  i:=n;
  while t[i-1]+t[1]>2*t[2] do
  begin
    inc(a,t[1]+t[i]+2*t[2]);
    dec(i,2);
  end;
  for i:=3 to i do inc(a,t[1]+t[i]);
  write(a);
  close(input); close(output);
end.