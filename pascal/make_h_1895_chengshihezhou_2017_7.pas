program make_h_1895_chengshihezhou_2017_7_12;
var
  n,l,i,j:longint;
begin
  randomize;
  n:=random(200000)+1;
  writeln(n);
  for i:=1 to n do
  begin
    l:=random(9)+2;
    for j:=1 to l do write(chr(random(26)+65));
    writeln(' ',chr(random(26)+65),chr(random(26)+65));
  end;
end.

