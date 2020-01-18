var
  a:array[1..1000] of longint;
  n,i,j,ans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
function f1(k,l,r:longint):longint;
var m:longint;
begin
  while l<=r do
  begin
    m:=(l+r)div 2;
    if a[m]-a[j]>=k
    then r:=m-1
    else l:=m+1;
  end;
  //writeln('1 ',i,' ',j,' ',a[i],' ',a[j],' ',l,' ',m,' ',r);
  exit(l);
end;
function f2(k,l,r:longint):longint;
var m:longint;
begin
  while l<=r do
  begin
    m:=(l+r)div 2;
    if a[m]-a[j]<=k
    then l:=m+1
    else r:=m-1;
  end;
  //writeln('2 ',i,' ',j,' ',a[i],' ',a[j],' ',l,' ',m,' ',r);
  exit(r);
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
  assign(input,'baseball.in'); assign(output,'baseball.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do readln(a[i]);
  sort(1,n);
  for i:=1 to n-2 do
    for j:=i+1 to n-1 do ans:=ans+max(f2(2*(a[j]-a[i]),j+1,n)-f1(a[j]-a[i],j+1,n)+1,0);
  writeln(ans);
  close(input); close(output);
end.