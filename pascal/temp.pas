const oo=maxlongint;
var
n,i,j,k:longint;
a:array[0..201]of int64;
f:array[1..200]of int64;
pw:array[0..31]of int64;
function min(a,b:int64):int64;
  begin if a<b then exit(a);exit(b);end;
begin
pw[0]:=1;
for i:=1 to 31 do pw[i]:=pw[i-1]*2;
read(n);f[1]:=0;
for i:=1 to n do read(a[i]);
for i:=2 to n do
  begin
    f[i]:=oo;k:=i-1;
	for j:=i-1 downto 1 do
	  begin
	    while(k>=1)and(a[k]+pw[j-k]<a[i])do dec(k);
		if k=0 then break;
		f[i]:=min(f[i],f[j]+j-k+1);
	  end;
  end;
if f[n]<>oo then write(f[n])else write(-1);
end.