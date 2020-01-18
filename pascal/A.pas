const x:array[1..5] of byte=(1,0,0,0,1);
var
  n,a:array[1..1005] of byte;
  i,j,l:integer;
  s:ansistring;
begin
  assign(input,'a.in'); assign(output,'a.out');
  reset(input); rewrite(output);
  read(s);
  l:=length(s);
  for i:=1 to l do val(s[i],n[l-i+1]);
  for i:=1 to 5 do
    for j:=1 to l do inc(a[i+j-1],n[j]*x[i]);
  inc(l,4);
  for i:=1 to l do
  begin
    inc(a[i+1],a[i]div 2);
    a[i]:=a[i]mod 2;
  end;
  if a[l+1]>0 then inc(l);
  for i:=l downto 1 do write(a[i]);
  close(input); close(output);
end.



