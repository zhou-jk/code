program htm_youchongfuyuansudepailiewenti1266_shensolianxi_2016_11_5;
var
  n,i:integer;
  r:char;
  a:array['a'..'z'] of integer;
  ans:array[1..500] of char;
  num:longint;
procedure dfs(k:integer);
var
  i:char;
  j:integer;
begin
  if k=n+1 then
  begin
    for j:=1 to n do write(ans[j]);
    writeln;
    inc(num);
    exit;
  end;
  for i:='a' to 'z' do
    if a[i]>0 then
    begin
      ans[k]:=i;
      dec(a[i]);
      dfs(k+1);
      inc(a[i]);
    end;
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(r);
    inc(a[r]);
  end;
  dfs(1);
  writeln(num);
end.

