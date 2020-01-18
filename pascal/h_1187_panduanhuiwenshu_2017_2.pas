program h_1187_panduanhuiwenshu_2017_2_25;
var
  a1,b1:array[1..3] of byte;
  ans:integer;
  a,b:string;
function max(a,b:byte):byte;
begin
  if a>b then exit(a);
  exit(b);
end;
function min(a,b:byte):byte;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  readln(a,b);
  for i:=1 to 3 do
  begin
    val(a[i],a1[i]); val(b[i],b1[i]);
  end;
  ans:=t((b1[1]-a1[1]))

