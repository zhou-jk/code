program bs_1827_xulie_2017_2_8;
var
  a:array[0..100003] of longint;
  n,k,i:longint;
  ans:int64;
function c(m,n:longint):int64;
var i:longint;
begin
  if n>m then exit(0);
  c:=1;
  for i:=m-n+1 to m do c:=c*i div(i+n-m);
end;
procedure sort(l,r:longint);
var
  i,j,x,y:longint;
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
  readln(n,k);
  for i:=1 to n do read(a[i]);
  sort(1,n);
  //for i:=1 to n do write(a[i],' ');
  for i:=k to n do
  begin
    inc(ans,c(i-1,k-1)*a[i]mod 1000000007);
    ans:=ans mod 1000000007;
  end;
  writeln(ans);
end.
