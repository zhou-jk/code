//PrayerOJ 1674
type num=array[0..100] of byte;
var
  f:array[0..500] of integer;
  g:array[0..500] of num;
  n,m,v,w,i,j,k,t:integer;
function max(a,b:byte):byte;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure plus(var a,b:num);
begin
  t:=0; a[0]:=max(a[0],b[0]);
  for k:=1 to a[0] do
  begin
    inc(a[k],b[k]+t);
    t:=a[k]div 10;
    a[k]:=a[k]mod 10;
  end;
  if t>0 then
  begin
    inc(a[0]);
    a[a[0]]:=t;
  end;
end;
begin
  read(n,m);
  for i:=0 to m do
  begin
    g[i,0]:=1; g[i,1]:=1;
  end;
  for i:=1 to n do
  begin
    read(v,w);
    for j:=m downto w do
      if f[j-w]+v>f[j]
      then begin
             f[j]:=f[j-w]+v;
             g[j]:=g[j-w];
           end
      else if f[j-w]+v=f[j] then plus(g[j],g[j-w]);
  end;
  writeln(f[m]);
  for i:=g[m,0] downto 1 do write(g[m,i]);
end.

