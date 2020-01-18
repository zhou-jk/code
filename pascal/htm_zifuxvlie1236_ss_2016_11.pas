program htm_zifuxulie1236_shenso_2016_11_9;
var
  n:integer;
  ans:longint;
  a:string[12];
procedure dfs(k:integer);
var
  i:integer;
  j:char;
begin
  if k=n+1 then
  begin
    for i:=1 to n-3 do if (a[i]=a[i+2])and(a[i+1]=a[i+3]) then exit;
    inc(ans);
    exit;
  end;
  for j:='A' to 'C' do
  begin
    a[k]:=j;
    dfs(k+1);
  end;
end;
begin
  readln(n);
  dfs(1);
  writeln(ans);
end.


