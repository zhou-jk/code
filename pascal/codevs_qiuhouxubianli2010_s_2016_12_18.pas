program codevs_qiuhouxubianli2010_shu_2016_12_18;
var
  a,b:string;
  n:integer;
procedure dfs(l1,r1,l2,r2:integer);
var i:integer;
begin
  if l1>r1 then exit;
  for i:=l2 to r2 do
    if b[i]=a[l1] then break;
  dfs(l1+1,i-l2+l1,l2,i-1);
  dfs(i-l2+l1+1,r1,i+1,r2);
  write(b[i]);
end;
begin
  readln(a);
  readln(b);
  n:=length(a);
  dfs(1,n,1,n);
end.

