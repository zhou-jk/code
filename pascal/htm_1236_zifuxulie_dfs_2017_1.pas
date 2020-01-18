program htm_1236_zifuxulie_dfs_2017_1_25;
var
  ans:longint;
  a:string;
  n,i:byte;
procedure dfs(k:byte);
var i:char;
begin
  if k=n+1 then
  begin
    inc(ans);
    exit;
  end;
  for i:='A' to 'C' do
    if (k<4)or((a[k-3]<>a[k-1])or(a[k-2]<>i)) then
    begin
      a[k]:=i;
      dfs(k+1);
    end;
end;
begin
  readln(n);
  for i:=1 to n do a:=a+' ';
  dfs(1);
  writeln(ans);
end.
