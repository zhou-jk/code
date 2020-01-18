program h_1230_paizuoyi_tanxin_2017_8_18;
type arr=array[1..1999] of integer;
var
  m,n,k,l,d,x,y,p,q,i:integer;
  a,b,sa,sb:arr;
function min(a,b:integer):integer;
begin
  if a<b then exit(a);
  exit(b);
end;
procedure swap(var a,b:integer);
var t:integer;
begin
  t:=a; a:=b; b:=t;
end;
procedure sort(var a,s:arr;l,r:integer);
var i,j,x:integer;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]>x do inc(i);
    while x>a[j] do dec(j);
    if i<=j then
    begin
      swap(a[i],a[j]); swap(s[i],s[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(a,s,l,j);
  if i<r then sort(a,s,i,r);
end;
procedure sort1(var a,s:arr;l,r:integer);
var i,j,x:integer;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
      swap(a[i],a[j]); swap(s[i],s[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort1(a,s,l,j);
  if i<r then sort1(a,s,i,r);
end;
begin
  read(m,n,k,l,d);
  dec(m); dec(n);
  for i:=1 to m do sa[i]:=i;
  for i:=1 to n do sb[i]:=i;
  for i:=1 to d do
  begin
    read(x,y,p,q);
    if x=p
    then inc(b[min(y,q)])
    else inc(a[min(x,p)]);
  end;
  sort(a,sa,1,m); sort(b,sb,1,n);
  sort1(sa,a,1,k); sort1(sb,b,1,l);
  for i:=1 to k-1 do write(sa[i],' ');
  writeln(sa[k]);
  for i:=1 to l-1 do write(sb[i],' ');
  write(sb[l]);
end.

