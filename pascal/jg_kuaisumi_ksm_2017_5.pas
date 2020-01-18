program jg_kuaisumi_kuaisumi_2017_5_21;
var
  a,b,c:qword;
function ksm(k:qword):qword;
begin
  if k=1 then exit(a);
  ksm:=sqr(ksm(k div 2))mod c;
  if k mod 2=1 then ksm:=ksm*a mod c;
end;
begin
  readln(a,b,c);
  a:=a mod c;
  writeln(ksm(b));
end.