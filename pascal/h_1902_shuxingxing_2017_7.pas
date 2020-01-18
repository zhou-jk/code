program h_1902_shuxingxing_2017_7_23;
var
  x1,x2,y1,y2:int64;
  n,i,a,b:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
function max(a,b:int64):int64;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  readln(n);
  x2:=maxlongint; y2:=maxlongint;
  for i:=1 to n do
  begin
    readln(a,b);
    x1:=max(x1,a); x2:=min(x2,a); y1:=max(y1,b); y2:=min(y2,b);
  end;
  writeln(sqr(max(x1-x2,y1-y2)));
end.
