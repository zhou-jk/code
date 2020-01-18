var
  c:array[1..12,1..3] of byte;
  v,f:array[0..12] of integer;
  n,i,j,ans:integer;
procedure dfs(k,s:integer);
var i,t:byte;
begin
  if (s<f[k-1])or(f[k-1]=0) then f[k-1]:=s;
  if k=n+1 then
  begin
    if s<ans then ans:=s;
    exit;
  end;
  if s+f[n-k+1]>=ans then exit;
  for i:=1 to n do
    if v[i]=0 then
    begin
      v[i]:=k;
      t:=0;
      for j:=1 to 3 do
        if v[c[i,j]]>0 then inc(t,k-v[c[i,j]]);
      dfs(k+1,s+t);
      v[i]:=0;
    end;
end;
begin
  assign(input,'haywire.in'); assign(output,'haywire.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do
    for j:=1 to 3 do read(c[i,j]);
  ans:=maxint;
  dfs(1,0);
  writeln(ans);
  close(input); close(output);
end.
