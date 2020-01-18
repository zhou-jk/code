var
  f:array[0..50,0..50,0..1] of longint;
  a,b,s:array[0..50] of longint;
  n,c,i,j,t:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
procedure swap(var a,b:longint);
begin
  t:=a; a:=b; b:=t;
end;
procedure sort(l,r:byte);
var i,j,x:integer;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
      swap(a[i],a[j]); swap(b[i],b[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  read(n,c);
  for i:=1 to n do read(a[i],b[i]);
  //sort(1,n);
  for i:=1 to n do s[i]:=s[i-1]+b[i];
  fillchar(f,sizeof(f),127);
  f[0,1,1]:=(a[c+1]-a[c])*(s[n]-b[c]); f[1,0,0]:=(a[c]-a[c-1])*(s[n]-b[c]);
  for i:=1 to c-1 do
    for j:=1 to n-c do
    begin
      f[i,j,0]:=min(f[i-1,j,0]+abs(a[c-i+1]-a[c-i])*(s[n]-s[c+j]+s[c-i]),f[i-1,j,1]+abs(a[c+j]-a[c-i])*(s[n]-s[c+j]+s[c-i]));
      f[i,j,1]:=min(f[i,j-1,0]+abs(a[c+j]-a[c-i])*(s[n]-s[c+j-1]+s[c-i-1]),f[i,j-1,1]+abs(a[c+j]-a[c+j-1])*(s[n]-s[c+j-1]+s[c-i-1]));
	  //writeln(i,' ',j,' ',f[i,j,0],' ',f[i,j,1]);
	end;
  write(min(f[c-1,n-c,0],f[c-1,n-c,1]));
end.