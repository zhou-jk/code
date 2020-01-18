program codevs_2058_kuohaoxulie_2017_4_26;
var
  s1:array[1..2000000] of char;
  s:ansistring;
  n,i,j,l:longint;
  b:boolean;
procedure p(c:char);
begin
  if (l>0)and(s1[l]=c)
  then dec(l)
  else b:=false;
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(s);
    b:=true; l:=0;
    for j:=1 to length(s) do
    begin
      if (s[j]='(')or(s[j]='[')or(s[j]='{')or(s[j]='<') then
      begin
        inc(l);
        s1[l]:=s[j];
      end;
      if s[j]=')' then p('(');
      if s[j]=']' then p('[');
      if s[j]='}' then p('{');
      if s[j]='>' then p('<');
      if not b then break;
    end;
    if l>0 then b:=false;
    writeln(b);
  end;
end.