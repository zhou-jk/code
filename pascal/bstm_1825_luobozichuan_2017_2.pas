program bstm_1825_luobozichuan_2017_2_6;
var
  s:array[-1999999..2000000] of char;
  co,cx,mo,mx,ans:longint;
procedure dfs(o,x:longint);
var i:longint;
begin
  if o+x>ans then ans:=o+x;
  if o<co then
    for i:=o+x downto o+x-mo+1 do
      if s[i]<>'O' then
      begin
        s[o+x+1]:='O';
        dfs(o+1,x);
        break;
      end;
  if x<cx then
    for i:=o+x downto o+x-mx+1 do
      if s[i]<>'X' then
      begin
        s[o+x+1]:='X';
        dfs(o,x+1);
        break;
      end;
end;
begin
  while not eof do
  begin
    readln(co,cx,mo,mx);
    ans:=0;
    dfs(0,0);
    writeln(ans);
  end;
end.

