program h_1894_gancaodui_2017_7_12;
var
  w:array[1..100000] of longint;
  n,q,a,b,i,l,r,m,ans,t:longint;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=w[(l+r)div 2];
  repeat
    while w[i]<x do inc(i);
    while x<w[j] do dec(j);
    if i<=j then
    begin
      y:=w[i]; w[i]:=w[j]; w[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
function find(k:longint):longint;
begin
  if k<w[1] then exit(0);
  l:=1; r:=n;
  while l<=r do
  begin
    m:=(l+r)div 2;
    if w[m]<=k
    then begin
           find:=m;
           l:=m+1;
         end
    else r:=m-1;
  end;
  //writeln('*',find);
end;
begin
  readln(n,q);
  for i:=1 to n do read(w[i]);
  sort(1,n);
  for i:=1 to q do
  begin
    readln(a,b);
    t:=find(a);
    ans:=find(b)-t;
    if (t>0)and(w[t]=a) then inc(ans);
    writeln(ans);
  end;
end.
