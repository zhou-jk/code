program htm_1772_panduandazhishu_2017_1_30;
var
  n,i,j,num:longint;
  t:boolean;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(num);
    t:=true;
    for j:=2 to trunc(sqrt(num)) do
      if num mod j=0 then
      begin
        writeln('NO');
        t:=false;
        break;
      end;
    if t then writeln('YES');
  end;
end.