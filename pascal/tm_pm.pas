var
  a:array[1..100] of longint;
  b:array[1..100] of real;
  n,k,i:longint;
procedure px(s,t:longint);
  var
    m,j,c,d:longint;
    e:array[1..100] of real;
    f:array[1..100] of longint;
  begin
    if s=t then exit;
    m:=(s+t) div 2;
    px(s,m);
    px(m+1,t);
    c:=s;
    j:=m+1;
    d:=s;
    while (c<=m) and (j<=t) do
      if b[c]>=b[j] then
        begin
          e[d]:=b[c]; f[d]:=a[c]; inc(c); inc(d);
        end
      else
        begin
          e[d]:=b[j]; f[d]:=a[j]; inc(j); inc(d);
        end;
    while c<=m do
      begin
        e[d]:=b[c]; f[d]:=a[c]; inc(c); inc(d);
      end;
    while j<=t do
      begin
        e[d]:=b[j]; f[d]:=a[j]; inc(j); inc(d);
      end;
    for i:=s to t do
      begin
        b[i]:=e[i];
        a[i]:=f[i];
      end;
  end;
begin
  readln(n,k);
  for i:=1 to n do
    readln(a[i],b[i]);
  px(1,n);
  writeln(a[k],' ',b[k]:0:1);
  readln;
end.
