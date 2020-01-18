program h_1228_sanguoyouxi_tanxi_2017_8_18;
var
  a,b,c:array[1..124750] of longint;
  v:array[1..500] of boolean;
  n,i,j,t:longint;
procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a; a:=b; b:=t;
end;
procedure sort(l,r:longint);
var i,j,x:longint;
begin
  i:=l; j:=r; x:=c[(l+r)div 2];
  repeat
    while c[i]>x do inc(i);
    while x>c[j] do dec(j);
    if i<=j then
    begin
      swap(a[i],a[j]); swap(b[i],b[j]); swap(c[i],c[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  read(n);
  for i:=1 to n-1 do
    for j:=1 to n-i do
    begin
      inc(t);
      read(c[t]);
      a[t]:=i; b[t]:=i+j;
    end;
  sort(1,t);
  writeln(1);
  for i:=1 to t do
  begin
    if v[a[i]]or v[b[i]] then
    begin
      write(c[i]);
      exit;
    end;
    v[a[i]]:=true; v[b[i]]:=true;
  end;
end.