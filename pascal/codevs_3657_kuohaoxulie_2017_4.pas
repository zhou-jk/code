program codevs_3657_kuohaoxulie_2017_4_26_X;
var
  s1:array[1..100] of char;
  s:string;
  i,j,l,ans:byte;
procedure p(c:char);
var i,j:byte;
begin
  for i:=l downto 1 do
    if s1[i]=c then
    begin
      dec(l);
      for j:=i to l do s1[j]:=s1[j+1];
      exit;
    end;
  writeln('#');
  inc(ans);
end;
begin
  readln(s);
  for i:=1 to length(s) do
  begin
    if (s[i]='(')or(s[i]='[')or(s[i]='{')or(s[i]='<') then
    begin
      inc(l);
      s1[l]:=s[i];
    end;
    if s[i]=')' then p('(');
    if s[i]=']' then p('[');
    if s[i]='}' then p('{');
    if s[i]='>' then p('<');
    for j:=1 to l do write(s1[j]);
    writeln;
  end;
  writeln(ans+l);
end.
