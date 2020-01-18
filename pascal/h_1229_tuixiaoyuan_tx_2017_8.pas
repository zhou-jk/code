program h_1229_tuixiaoyuan_tanxin_2017_8_18;
var
  s,a,b,f:array[1..100001] of longint;
  n,i,t,ts,ta:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a; a:=b; b:=t;
end;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l; j:=r; x:=a[(l+r)div 2];
  repeat
    while a[i]>x do inc(i);
    while x>a[j] do dec(j);
    if i<=j then
    begin
      swap(s[i],s[j]); swap(a[i],a[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  read(n);
  for i:=1 to n do read(s[i]);
  for i:=1 to n do read(a[i]);
  for i:=n downto 1 do f[i]:=max(f[i+1],s[i]*2+a[i]);
  b:=s;
  sort(1,n);
  t:=1;
  for i:=1 to n do
  begin
    inc(ta,a[i]); ts:=max(ts,s[i]);
    while (t<=n)and(b[t]<=ts) do inc(t);  //yi ding yao <=,fou ze hui chong fu(WA)
    writeln(max(ta+2*ts,ta-a[i]+f[t]));
  end;
end.