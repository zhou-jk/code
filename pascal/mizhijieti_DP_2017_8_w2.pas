program luogu_2433_mizhijieti_DP_2017_8_20_w2;
//PrayerOJ 1992  luogu 1929/2433
var
  h,f:array[1..200] of longint;
  s:array[0..32] of int64;
  n,i,j,k:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  read(n);
  for i:=1 to n do read(h[i]);
  s[0]:=1;
  for i:=1 to 32 do s[i]:=s[i-1]*2;
  for i:=2 to n do
  begin
    f[i]:=maxlongint;
    k:=i-1;
    for j:=i-1 downto 1 do
    begin
      k:=min(j,k);
      while (k>=1)and(h[k]+s[j-k]<h[i]) do dec(k);
      if k=0 then break;
      f[i]:=min(f[i],f[j]+j-k+1);
    end;
    if f[i]=maxlongint then
    begin
      write(-1);
      exit;
    end;
  end;
  write(f[n]);
end.