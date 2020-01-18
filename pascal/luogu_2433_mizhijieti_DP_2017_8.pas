program luogu_2433_mizhijieti_DP_2017_8_19;
//PrayerOJ 1992
var
  h,f:array[1..200] of longint;
  s:array[-1..32] of int64;
  n,i,j,k:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  read(n);
  for i:=1 to n do read(h[i]);
  s[-1]:=-maxlongint; s[0]:=1;
  for i:=1 to 32 do s[i]:=s[i-1]*2;
  for i:=2 to n do
  begin
    f[i]:=maxlongint;
    k:=32;
    for j:=1 to i-1 do
    begin
      while h[j]+s[k]>=h[i] do dec(k);
      inc(k);
      if j+k<i then f[i]:=min(f[i],f[j+k]+k+1);
    end;
	if f[i]=maxlongint then
	begin
	  write(-1);
	  exit;
	end;
  end;
  write(f[n]);
end.
