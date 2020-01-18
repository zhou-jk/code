uses math;
var
  xi,yi,x,y:array[1..100] of longint;
  l:array[1..4] of integer;
  n,B,m,i,j,k,m_:longint;
procedure px(s,t:integer);
var m,i,j,k:integer;
begin
  if s=t then exit;
  m:=(s+t) div 2;
  px(s,m);
  px(m+1,t);
  i:=s;
  j:=m+1;
  k:=s;
  while (i<=m)and(j<=t) do
    if xi[i]<=xi[j]
    then begin x[k]:=xi[i]; inc(i); inc(k); end
    else begin x[k]:=xi[j]; inc(i); inc(k); end;
  while i<=m do begin x[k]:=xi[i]; inc(i); inc(k); end;
  while i<=m do begin x[k]:=xi[j]; inc(j); inc(k); end;
  i:=s;
  j:=m+1;
  k:=s;
  while (i<=m)and(j<=t) do
    if yi[i]<=yi[j]
    then begin y[k]:=yi[i]; inc(i); inc(k); end
    else begin y[k]:=yi[j]; inc(i); inc(k); end;
  while i<=m do begin y[k]:=yi[i]; inc(i); inc(k); end;
  while i<=m do begin y[k]:=yi[j]; inc(j); inc(k); end;
end;
begin
  readln(n,B);
  for i:=1 to n do
    readln(xi[i],yi[i]);
  px(1,n);
  m:=100;
  for i:=1 to n-1 do
    for j:=1 to n-1 do
    begin
      l[1]:=0; l[2]:=0; l[3]:=0; l[4]:=0;
      for k:=1 to n do
        if xi[k]<=x[i]
        then if yi[k]<=y[j]
             then inc(l[1])
             else inc(l[2])
        else if yi[k]<=y[j]
             then inc(l[3])
             else inc(l[4]);
      m_:=max(max(max(l[1],l[2]),l[3]),l[4]);
      if m_<m then m:=m_;
    end;
  writeln(m);
end.


