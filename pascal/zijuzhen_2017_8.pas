//PrayerOJ 1211
var
  a,ld,f:array[1..16,1..16] of longint;
  cr,rd:array[1..16] of longint;
  n,m,r,c,i,j,k,ans,t:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
procedure dp;
begin
   fillchar(ld,sizeof(ld),0); fillchar(rd,sizeof(rd),0);
   for i:=1 to m do
     for j:=1 to r-1 do inc(rd[i],abs(a[cr[j],i]-a[cr[j+1],i]));
   for i:=1 to m-1 do
     for j:=i+1 to m do
       for k:=1 to r do inc(ld[i,j],abs(a[cr[k],i]-a[cr[k],j]));
   for i:=1 to m do f[1,i]:=rd[i];
   for i:=2 to c do
     for j:=i to m do
     begin
       t:=maxlongint;
       for k:=i-1 to j-1 do t:=min(t,f[i-1,k]+ld[k,j]);
       f[i,j]:=t+rd[j];
     end;
   for i:=c to m do ans:=min(ans,f[c,i]);
end;
procedure dfs(k,p:byte);
var i:byte;
begin
  if k=r then
  begin
    dp;
    exit;
  end;
  for i:=p+1 to n-(r-k)+1 do
  begin
    cr[k+1]:=i;
    dfs(k+1,i);
  end;
end;
begin
  read(n,m,r,c);
  for i:=1 to n do
    for j:=1 to m do read(a[i,j]);
  ans:=maxlongint;
  dfs(0,0);
  write(ans);
end.