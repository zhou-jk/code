program h_1167_string_2017_8_13;
var
  s:ansistring;
  i,n,f,ans:longint;
begin
  readln(s);
  n:=length(s);
  for i:=n-3 downto 1 do
  begin
    if copy(s,i,4)='bear' then f:=i+3;
    if f>0 then inc(ans,n-f+1);
  end;
  writeln(ans);
end.
