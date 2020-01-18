program htm_1718_qiuNgeshudezuidagongyueshuhezuixiaogongbeishu_2017_1_30;
var
  a:array[1..100] of integer;
  n,i,gcd:integer;
  lcm:int64;
function g(p:int64;q:integer):integer;
begin
  if p mod q=0 then exit(q);
  exit(g(q,p mod q));
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  gcd:=a[1]; lcm:=a[1];
  for i:=2 to n do
  begin
    gcd:=g(gcd,a[i]);
    lcm:=lcm*a[i] div g(lcm,a[i]);
  end;
  writeln(gcd);
  writeln(lcm);
end.

