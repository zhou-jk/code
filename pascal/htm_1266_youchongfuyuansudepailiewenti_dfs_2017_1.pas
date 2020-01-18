program htm_1266_youchongfuyuansudepailiewenti_dfs_2017_1_25;
var
  b:array['a'..'z'] of integer;
  r:array[1..500] of char;
  n,i,ans:longint;
  s:ansistring;
procedure dfs(k:integer);
var i:char;
begin
  if k=n+1 then
  begin
    inc(ans);
    writeln(s);
    exit;
  end;
  for i:='a' to 'z' do
    if b[i]>0 then
    begin
      dec(b[i]);
      s[k]:=i;
      dfs(k+1);
      inc(b[i]);
    end;
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(r[i]);
    inc(b[r[i]]);
    s:=s+' ';
  end;
  dfs(1);
  writeln(ans);
end.

