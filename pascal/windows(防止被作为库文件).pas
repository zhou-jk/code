var
  r1,s1,r2,s2:array[1..100]of integer;
  n,i,ra,sa,rb,sb,ans:integer;
  b:array[1..100]of boolean;
procedure dfs(k:byte);
var i:byte;
begin
  for i:=k+1 to n do
    if not b[i]and(r2[i]>r1[k])and(s2[i]<s1[k])and(r1[i]<=r1[k])and(s1[i]>=s1[k]) then
    begin
      b[i]:=true;
      dfs(i);
    end;
end;
begin
  assign(input,'windows.in'); assign(output,'windows.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    readln(ra,sa,rb,sb);
    r1[i]:=ra; s1[i]:=sb; r2[i]:=rb; s2[i]:=sa;
  end;
  dfs(1);
  for i:=1 to n do
    if b[i] then inc(ans);
  writeln(ans+1);
  close(input); close(output);
end.
