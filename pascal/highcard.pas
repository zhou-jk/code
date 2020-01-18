var
  a,b:array[1..50001] of longint;
  v:array[1..100000] of boolean;
  n,i,j,t,ans:longint;
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
  assign(input,'highcard.in'); assign(output,'highcard.out');
  reset(input); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(a[i]);
    v[a[i]]:=true;
  end;
  for i:=1 to 2*n do
    if not v[i] then
    begin
      inc(t);
      b[t]:=i;
    end;
  sort(1,n);
  b[n+1]:=maxlongint;
  for i:=1 to n do
  begin
    inc(j);
    while b[j]<a[i] do inc(j);
    if j=n+1 then break;
    inc(ans);
  end;
  write(ans);
  close(input); close(output);
end.