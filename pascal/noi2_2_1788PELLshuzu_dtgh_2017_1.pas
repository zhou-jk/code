program noi2_2_1788PELLshuzu_dongtaiguihua_2017_1_1;
var
  a:array[1..1000000] of integer;
  n,k,b,i,j:longint;
begin
  readln(n);
  a[1]:=1; a[2]:=2;
  b:=2;
  for i:=1 to n do
  begin
    readln(k);
    for j:=b+1 to k do a[j]:=(2*a[j-1]+a[j-2])mod 32767;
    if k>b then b:=k;
    writeln(a[k]);
  end;
end.
