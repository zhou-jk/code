program h_1932_baseball_dandiaoxing_2017_8_14;
var
  a:array[1..5001] of longint;
  n,i,j,t1,t2:longint;
  ans:int64;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
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
  readln(n);
  for i:=1 to n do readln(a[i]);
  sort(1,n);
  for i:=2 to n-1 do
  begin
    t1:=i+1; t2:=t1;
    for j:=i-1 downto 1 do
      if a[j]<a[i] then
	  begin
	    while ((a[t1]=a[i])or(a[t1]-a[i]<a[i]-a[j]))and(t1<=n) do inc(t1);
	    while (a[t2]-a[i]<=2*(a[i]-a[j]))and(t2<=n) do inc(t2);
	    inc(ans,max(t2-t1,0));
	  end;
  end;
  writeln(ans);
end.
