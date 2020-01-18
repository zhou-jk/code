program noi_2_6_1768_zuidazijuzhen_dongtaiguihua_2017_2_9;
uses math;
var
  a,col:array[0..100,0..100] of integer;
  f:array[0..100] of integer;
  n,i,j,k,ans:integer;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
    begin
      read(a[i,j]);
      col[j,i]:=col[j,i-1]+a[i,j];
    end;
  for i:=1 to n do
    for j:=i to n do
      for k:=1 to n do
      begin
        f[k]:=max(col[k,j]-col[k,i-1],f[k-1]+col[k,j]-col[k,i-1]);
        ans:=max(ans,f[k]);
      end;
  writeln(ans);
end.

