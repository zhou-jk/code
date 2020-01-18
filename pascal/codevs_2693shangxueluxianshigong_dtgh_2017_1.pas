program codevs_2693shangxueluxianshigong_dongtaiguihua_2017_1_18;
var
  s:array[1..17,1..17] of longint;
  n,x,y,i,j,a,b:integer;
begin
  readln(a,b);
  for i:=1 to b do
    for j:=1 to a do s[i,j]:=1;
  readln(n);
  for i:=1 to n do begin readln(x,y); s[y,x]:=0; end;
  {for i:=b downto 1 do
  begin
    for j:=1 to a do write(s[i,j]);
    writeln;
  end;}
  for i:=a-1 downto 1 do if s[b,i]>0 then s[b,i]:=s[b,i+1];
  for i:=b-1 downto 1 do
    for j:=a downto 1 do
      if s[i,j]>0 then {begin} s[i,j]:=s[i+1,j]+s[i,j+1]; {writeln(s[i,j],' ',i,' ',j); end;}
  writeln(s[1,1]);
end.
