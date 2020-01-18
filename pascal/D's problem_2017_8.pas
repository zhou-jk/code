//Tyvj 4812
var
  l,i,s0,s1:longint;
  s:ansistring;
begin
  read(s);
  l:=length(s);
  for i:=1 to l do
    if s[i]='0' then inc(s0);
  for i:=1 to l do
  begin
    if s[i]='0'
    then dec(s0)
    else inc(s1);
    if s0=s1 then
    begin
      write(i);
      exit;
    end;
  end;
  write(l+1);
end.
