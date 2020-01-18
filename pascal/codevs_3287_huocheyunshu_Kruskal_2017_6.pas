program codevs_3287_huocheyunshu_Kruskal_2017_6_14;
type edge=record
            a,b,z:longint;
          end;
var
  f,next,l,v:array[0..10000] of longint;
  e:array[1..50000] of edge;
  n,m,x,y,q,i,ne,fa,fb:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  min:=b;
end;
function gf(k:longint):longint;
begin
  if f[k]=k
  then exit(k)
  else f[k]:=gf(f[k]);
  gf:=f[k];
end;
procedure dfs(k,s:longint);
begin
  if k=0 then exit;
  v[k]:=min(s,l[k]);
  dfs(next[k],k);
end;
procedure dfs1(k,s:longint);
begin
  if (v[k]>-1)or(k=0) then
  begin
    writeln(min(v[k],s));
    exit;
  end;
  dfs1(next[k],min(s,l[k]));
end;
procedure sort(l,r:longint);
var
  i,j,x:longint;
  y:edge;
begin
  i:=l; j:=r; x:=e[(l+r) div 2].z;
  repeat
    while e[i].z>x do inc(i);
    while x>e[j].z do dec(j);
    if i<=j then
    begin
      y:=e[i]; e[i]:=e[j]; e[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(n,m);
  for i:=1 to m do with e[i] do readln(a,b,z);
  for i:=1 to n do f[i]:=i;
  sort(1,m);
  i:=0;
  while (ne<n-1)and(i<m) do
  begin
    inc(i);
    with e[i] do
    begin
      fa:=gf(a); fb:=gf(b);
      if fa<>fb then
      begin
        f[fa]:=f[fb]; l[a]:=z; //next[a]:=b;
        writeln(i,' ',a,' ',b,' ',z);
        inc(ne);
      end;
    end;
  end;
  readln(q);
  for i:=1 to q do
  begin
    readln(x,y);
    fillchar(v,40004,255);
    v[x]:=maxlongint;
    dfs(next[x],maxlongint);
    if v[y]>-1 then
    begin
      writeln(v[y]);
      break;
    end;
    dfs1(next[y],maxlongint);
  end;
end.






