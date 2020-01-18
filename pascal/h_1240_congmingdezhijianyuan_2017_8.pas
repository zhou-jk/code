program h_1240_congmingdezhijianyuan_2017_8_15;
var
  w,v,l,r,sum,t:array[0..200000] of longint;
  n,m,i,left,right,mid:longint;
  s,t1,t2:int64;
function calc(k:longint):int64;
begin
  for i:=1 to n do
  begin
    sum[i]:=sum[i-1]; t[i]:=t[i-1];
    if w[i]>=k then
    begin
      inc(sum[i]); inc(t[i],v[i]);
    end;
  end;
  calc:=0;
  for i:=1 to m do inc(calc,(sum[r[i]]-sum[l[i]-1])*(t[r[i]]-t[l[i]-1]));
end;
begin
  read(n,m,s);
  left:=maxlongint;
  for i:=1 to n do
  begin
    read(w[i],v[i]);
    if v[i]<left then left:=v[i];
    if v[i]>right then right:=v[i];
  end;
  inc(right);
  for i:=1 to m do read(l[i],r[i]);
  while left<=right do
  begin
    mid:=(left+right)div 2;
    if calc(mid)<s
    then right:=mid-1
    else left:=mid+1;
  end;
  t1:=s-calc(left); t2:=calc(right)-s;
  //writeln(left,' ',right);
  if t1<t2
  then write(t1)
  else write(t2);
end.