program codevs_3162_chaoshuwenti_DP_2017_4_8;
var
  sum,b,ans1,ans2:array[0..100] of longint;
  f:array[1..100,1..100] of longint;
  m,k,i,j,p,last,t:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  max:=b;
end;
begin
  readln(m,k);
  for i:=1 to m do
  begin
    read(b[i]);
    sum[i]:=sum[i-1]+b[i]; f[i,1]:=sum[i];
    for j:=2 to k do
    begin
      f[i,j]:=maxlongint;
      for p:=j-1 to i-1 do
        if f[i,j]>max(f[p,j-1],sum[i]-sum[p]) then f[i,j]:=max(f[p,j-1],sum[i]-sum[p]);
    end;
  end;
  p:=k; last:=m; t:=b[m];
  for i:=m-1 downto 1 do
    if (t+b[i]>f[m,k])or(i-1<p-1)
    then begin
           ans1[p]:=i+1; ans2[p]:=last; last:=i; t:=b[i];
           dec(p);
         end
    else inc(t,b[i]);
  ans1[1]:=1; ans2[1]:=ans1[2]-1;
  if ans1[2]=0 then ans2[1]:=last;
  for i:=1 to k do writeln(ans1[i],' ',ans2[i]);
end.



