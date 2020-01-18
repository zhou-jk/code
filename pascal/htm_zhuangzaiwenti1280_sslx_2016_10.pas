program htm_zhuangzaiwenti1280_shensoulianxi_2016_10_30;
var
  n,c,i,ans:integer;
  w:array[1..30] of integer;
procedure s(k,p:integer);
begin
  if p>c then exit;
  if p>ans then ans:=p;
  if k=n+1 then exit;
  s(k+1,p);
  s(k+1,p+w[k]);
end;
begin
  read(n,c);
  for i:=1 to n do read(w[i]);
  s(1,0);
  write(ans);
end.

