program h_1242_tuedukaixiao_erfenchazhao_2017_8_15;
var
  v:array[1..100000] of integer;
  n,m,i,l,r,mid,t,s:longint;
function check(k:longint):boolean;
begin
  t:=0; s:=0;
  for i:=1 to n do
    if t+v[i]<=k
    then inc(t,v[i])
    else begin
           t:=v[i];
           inc(s);
           if s>m then exit(false);
         end;
  if s<m
  then exit(true)
  else exit(false);
end;
begin
  read(n,m);
  for i:=1 to n do
  begin
    read(v[i]);
    if v[i]>l then l:=v[i];
    inc(r,v[i]);
  end;
  while l<=r do
  begin
    mid:=(l+r)div 2;
    if check(mid)
    then r:=mid-1
    else l:=mid+1;
  end;
  writeln(l);
end.
