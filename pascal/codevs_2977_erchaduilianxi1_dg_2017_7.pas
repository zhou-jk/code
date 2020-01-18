program h_2977_erchaduilianxi1_digui_2017_7_24;
var
  a:array[1..50000] of integer;
  n,i:word;
function solve(k:word):boolean;
begin
  if k>n div 2 then exit(true);
  solve:=(a[k]<=a[k*2])and solve(k*2);
  if k*2+1<=n then solve:=solve and(a[k]<=a[k*2+1])and solve(k*2+1);
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  if solve(1)
  then writeln('YES')
  else writeln('NO');
end.
