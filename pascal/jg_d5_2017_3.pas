program jg_d5_2017_3_12;
var
  n,i,a,b,t,ans:longint;
begin
  readln(n);
  ans:=maxlongint;
  for i:=1 to 3 do
  begin
    readln(a,b);
    t:=n div a;
    if n mod a>0 then inc(t);
    if t*b<ans then ans:=t*b;
  end;
  writeln(ans);
end.



