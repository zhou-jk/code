program codevs_1202qiuhe_2017_1_6;
var
  a,sum:longint;
  n,i:integer;
begin
  readln(n);
  for i:=1 to n do begin read(a); inc(sum,a); end;
  writeln(sum);
end.
