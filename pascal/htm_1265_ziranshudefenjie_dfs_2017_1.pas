program htm_1265_ziranshudehefenjie_dfs_2017_1_28;
var
  a:array[1..100000] of longint;
  n:longint;
procedure dfs(k,n,old:longint);
var i:longint;
begin
  if n=0 then
  begin
    if k>2 then
    begin
      for i:=1 to k-2 do write(a[i],'+');
      writeln(a[k-1]);
    end;
    exit;
  end;
  for i:=old to n div 2 do
  begin
    a[k]:=i;
    dfs(k+1,n-i,i);
  end;
  a[k]:=n;
  dfs(k+1,0,n);
end;
begin
  readln(n);
  dfs(1,n,1);
end.