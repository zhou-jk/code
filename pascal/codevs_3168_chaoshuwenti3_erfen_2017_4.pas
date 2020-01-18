program codevs_3168_chaoshuwenti3_erfen_2017_4_8;
var
  ans1,ans2:array[1..10000] of longint;
  b:array[1..1000000] of integer;
  m,k,i,l,r,sum,mid,last,p,t:longint;
function check(mid:longint):boolean;
var i,t,need:longint;
begin
  if b[1]>mid then exit(false);
  need:=1; t:=b[1];
  for i:=2 to m do
  begin
    if b[i]>mid then exit(false);
    if t+b[i]>mid
    then begin
           inc(need); t:=b[i];
         end
    else inc(t,b[i]);
  end;
  exit(need<=k);
end;
begin
  readln(m,k);
  for i:=1 to m do
  begin
    read(b[i]);
    inc(sum,b[i]);
  end;
  l:=0; r:=sum;
  while l<r do
  begin
    mid:=(l+r)div 2;
    if check(mid)
    then r:=mid
    else l:=mid+1;
  end;
  p:=k; last:=m; t:=b[m];
  for i:=m-1 downto 1 do
    if (t+b[i]>r)or(i-1<p-1)
    then begin
           ans1[p]:=i+1; ans2[p]:=last; last:=i; t:=b[i];
           dec(p);
         end
    else inc(t,b[i]);
  ans1[1]:=1; ans2[1]:=ans1[2]-1;
  if ans1[2]=0 then ans2[1]:=last;
  for i:=1 to k do writeln(ans1[i],' ',ans2[i]);
end.


