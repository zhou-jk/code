program bstm_1821_pingjunrenwu_2017_2_6;
var
  m:array[1..100000] of longint;
  n,i,num,m1,ans,ans1:longint;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(m[i]);
    inc(num,m[i]);
  end;
  m1:=num div n;
  if num mod n>0 then inc(m1);
  for i:=1 to n do
    if m[i]>m1 then inc(ans,m[i]-m1);
  for i:=1 to n do
    if m1-m[i]>1 then inc(ans1,m1-m[i]-1);
  if ans>ans1
  then writeln(ans)
  else writeln(ans1);
end.

