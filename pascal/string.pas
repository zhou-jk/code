type ar=array['A'..'N'] of byte;
var
  a:array[1..20,'A'..'N'] of integer;
  s:array[1..20] of ansistring;
  n,i,j,ans:integer;
  c:char;
  b:ar;
procedure dfs(k,s:integer;b:ar);
var i:char;
begin
  if k=n+1 then
  begin
    if s>ans then
    begin
      for i:='A' to 'N' do
        if b[i]>0 then exit;
      ans:=s;
    end;
    exit;
  end;
  dfs(k+1,s,b);
  for i:='A' to 'N' do
  begin
    inc(b[i],a[k,i]);
    b[i]:=b[i] mod 2;
  end;
  dfs(k+1,s+1,b);
end;
begin
  assign(input,'string.in'); assign(output,'string.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    readln(s[i]);
    for j:=1 to length(s[i]) do inc(a[i,s[i][j]]);
    for c:='A' to 'N' do a[i,c]:=a[i,c] mod 2;
  end;
  fillchar(b,sizeof(b),0);
  dfs(1,0,b);
  writeln(ans);
  close(input); close(output);
end.
