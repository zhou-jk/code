program noi2_2_1755feibonaqishulie2_dongtaiguihua_2017_1_1;
var
  f:array[1..1000000] of integer;
  n,i:integer;
  a,b,j:longint;
begin
  readln(n);
  f[1]:=1; f[2]:=1;
  b:=2;
  for i:=1 to n do
  begin
    readln(a);
    for j:=b+1 to a do begin f[j]:=f[j-1]+f[j-2]; f[j]:=f[j] mod 1000; end;
    if a>b then b:=a;
    writeln(f[a]);
  end;
end.
