var
  x,y:array[1..100000] of longint;
  n,d,i,j,k,t,a:longint;
procedure swap(var a,b:longint);
begin
  t:=a; a:=b; b:=t;
end;
procedure sort(l,r:longint);
var i,j,a:longint;
begin
  i:=l; j:=r; a:=y[(l+r)div 2];
  repeat
    while y[i]<a do inc(i);
    while a<y[j] do dec(j);
    if i<=j then
    begin
      swap(x[i],x[j]); swap(y[i],y[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  assign(input,'fpot.in'); assign(input,'fpot.out');
  reset(input); rewrite(output);
  read(n,d);
  for i:=1 to n do read(x[i],y[i]);
  sort(1,n);
  j:=2; a:=maxlongint;
  for i:=1 to n do
  begin
    while (j<=n)and(y[j]-y[i]<d) do inc(j);
    if j>n then break;
    for k:=j to n do
      if abs(x[i]-x[j])<a then a:=abs(x[i]-x[j]);
  end;
  write(a);
  close(input); close(output);
end.