program h_1243_chengjizuida_DFS_2017_3_18;
var
  a:array[1..40,0..40] of int64;
  n,m,i,j,num:integer;
  s:string;
  ans:int64;
procedure dfs(t,k:integer;s:int64);
var i:integer;
begin
  if k=m then
  begin
    if s*a[t+1,n]>ans then ans:=s*a[t+1,n];
    exit;
  end;
  for i:=t+1 to n-m+k do dfs(i,k+1,s*a[t+1,i]);
end;
begin
  readln(n,m);
  readln(s);
  for i:=1 to n do
    for j:=i to n do
    begin
      val(s[j],num);
      a[i,j]:=a[i,j-1]*10+num;
    end;
  dfs(0,0,1);
  writeln(ans);
end.

