program codevs_1297_yingbi_dfs_2017_2_25;
uses math;
var
  v,wmin,wmax:array[1..7] of byte;
  b:array[0..2500] of byte;
  n,w,i,ans:integer;
procedure dfs(k,t,va:integer);
var i,j:byte;
begin
  if k=n+1 then
  begin
    if t=w then b[va]:=1;
    exit;
  end;
  for i:=0 to (w-t)div wmin[k] do
    for j:=i*wmin[k] to min(i*wmax[k],w-t) do dfs(k+1,t+j,va+v[k]*i);
end;
begin
  readln(w);
  readln(n);
  for i:=1 to n do readln(v[i],wmin[i],wmax[i]);
  dfs(1,0,0);
  for i:=0 to 2500 do inc(ans,b[i]);
  writeln(ans);
end.