type arr=array[0..5000] of int64;
var
  n,m,i,j:longint;
  x,y,f:arr;
function min(a,b:int64):int64;
begin
  if a<b then exit(a);
  exit(b);
end;
procedure sort(var a:arr;l,r:longint);
var 
  i,j:longint;
  x,y:int64;
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
  if l<j then sort(a,l,j);
  if i<r then sort(a,i,r);
end;
begin
  assign(input,'tree.in'); assign(output,'tree.out');
  reset(input); rewrite(output);
  read(n);
  for i:=1 to n do read(x[i]);
  read(m);
  for i:=1 to m do read(y[i]);
  sort(x,1,n); sort(y,1,m);
  fillchar(f,sizeof(f),127);
  f[1]:=0;
  for i:=1 to n do
    for j:=min(m,i) downto 1 do
	  f[j]:=min(f[j],f[j-1])+abs(x[i]-y[j]);
  write(f[m]);
  close(input); close(output);
end.