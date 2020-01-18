program codevs_3112erchashujishu_shu_2016_12_30;
var
  n,i:integer;
  ans:int64;
begin
  readln(n);
  ans:=1;
  for i:=n+1 to 2*n do ans:=ans*i div(i-n);
  writeln(ans div(n+1));
end.
