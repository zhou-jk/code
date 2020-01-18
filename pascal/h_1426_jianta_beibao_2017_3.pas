program h_1426_jianta_beibao_2017_3_4;
var
  f:array[0..40000] of boolean;
  h,a,c:array[1..400] of word;
  k,i,j,p:word;
function min(a,b:word):word;
begin
  if a<b then exit(a);
  exit(b);
end;
procedure sort(l,r: longint);
var i,j,x,y: longint;
begin
  i:=l; j:=r; x:=a[(l+r) div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
      y:=h[i]; h[i]:=h[j]; h[j]:=y;
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      y:=c[i]; c[i]:=c[j]; c[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then
  sort(i,r);
end;
begin
  readln(k);
  for i:=1 to k do readln(h[i],a[i],c[i]);
  sort(1,k);
  f[0]:=true;
  for i:=1 to k do
    for j:=a[i] downto 1 do
      for p:=1 to min(c[i],j div h[i]) do
        if f[j-p*h[i]] then
        begin
          f[j]:=true;
          break;
        end;
  for i:=a[k] downto 0 do
    if f[i] then
    begin
      writeln(i);
      exit;
    end;
end.


