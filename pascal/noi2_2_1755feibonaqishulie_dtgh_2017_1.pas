program noi2_2_1755feibonaqishulie_dongtaiguihua_2017_1_1;
var
  s:array[1..20] of integer;
  n,a,b,i,j:integer;
begin
  readln(n);
  s[1]:=1; s[2]:=1;
  b:=2;
  for i:=1 to n do
  begin
    readln(a);
    for j:=b+1 to a do s[j]:=s[j-1]+s[j-2];
    if a>b then b:=a;
    writeln(s[a]);
  end;
end.
