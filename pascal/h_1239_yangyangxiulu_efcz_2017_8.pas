program h_1239_yangyangxiulu_erfenchazhao_2017_8_17;
var
  g,s:array[1..2000,0..2000] of longint;
  v:array[1..2000] of boolean;
  n,m,a,b,c,i,l,r,mid:longint;
procedure dfs(k:longint);
var i:longint;
begin
  v[k]:=false;
  for i:=1 to g[k,0] do
    if v[g[k,i]]and(s[k,g[k,i]]<=mid) then dfs(g[k,i]);
end;
function check:boolean;
begin
  fillchar(v,2000,1);
  dfs(1);
  for i:=1 to n do
    if v[i] then exit(false);
  exit(true);
end;
begin
  read(n,m);
  l:=maxlongint;
  fillchar(s,sizeof(s),127);
  for i:=1 to m do
  begin
    read(a,b,c);
    inc(g[a,0]); inc(g[b,0]);
    g[a,g[a,0]]:=b; g[b,g[b,0]]:=a;
    if c<s[a,b] then
    begin
      s[a,b]:=c; s[b,a]:=c;
    end;
    if c>r then r:=c; if c<l then l:=c;
  end;
  while l<r do
  begin
    mid:=(l+r)div 2;
    if check
    then r:=mid
    else l:=mid+1;
  end;
  write(l);
end.