//PrayerOJ 1999
var
  l,r:array[1..999] of integer;
  p,c,i,ans:integer;
procedure dfs(k,s:integer);
begin
  if k=0 then
  begin
    if s>ans then ans:=s;
    exit;
  end;
  dfs(l[k],s+1);
  dfs(r[k],s+1);
end;
begin
  read(p);
  for i:=1 to p-1 do read(c,l[c],r[c]);
  dfs(1,0);
  write(ans);
end.
