program htm_zhishuhuan_shensolianxi_2016_10_28;
var
  n,i,j:integer;
  d:boolean;
  a:array[1..17] of integer;
  b:array[1..17] of boolean;
  c:array[1..33] of boolean;
procedure qpl(k:integer);
var
  i:integer;
begin
  if k=n then
  begin
    for i:=2 to n do
      if not b[i] then
        if c[i+a[k-1]] and c[i+1] then
        begin
          a[k]:=i;
          qpl(k+1);
        end;
    exit;
  end;
  if k=n+1 then
  begin
    if d then writeln;
    d:=true;
    for i:=1 to n-1 do write(a[i],' ');
    write(a[n]);
    exit;
  end;
  for i:=2 to n do
    if not b[i] then
      if c[i+a[k-1]] then
      begin
        b[i]:=true; a[k]:=i;
        qpl(k+1);
        b[i]:=false;
      end;
end;
begin
  readln(n);
  a[1]:=1;
  for i:=1 to 2*n-1 do
  begin
    c[i]:=true;
    for j:=2 to trunc(sqrt(i)) do
      if i mod j=0 then begin c[i]:=false; break; end;
  end;
  qpl(2);
end.
