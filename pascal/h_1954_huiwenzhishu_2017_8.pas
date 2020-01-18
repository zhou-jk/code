program h_1954_huiwenzhishu_2017_8_3_TLE;
var
  ip:array[2..100000000] of boolean;
  p:array[1..5761455] of longint;
  a,b,i,j,t:longint;
procedure pd(n:longint);
var
  i,j:longint;
  s:string;
begin
  str(n,s);
  i:=1; j:=length(s);
  while i<j do
  begin
    if s[i]<>s[j] then exit;
    inc(i); dec(j);
  end;
  writeln(n);
end;
begin
  readln(a,b);
  for i:=2 to b do
  begin
    if not ip[i] then
    begin
      inc(t);
      p[t]:=i;
    end;
    for j:=1 to t do
    begin
      if i*p[j]>b then break;
      ip[i*p[j]]:=true;
      if i mod p[j]=0 then break;
    end;
  end;
  for i:=1 to t do
    if p[i]>=a then pd(p[i]);
  //writeln(t1);
end.
