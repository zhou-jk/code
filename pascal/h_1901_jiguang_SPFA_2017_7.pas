program h_1901_jiguang_SPFA_2017_7_14;
var
  x,y,d,s:array[1..100002] of longint;
  b:array[1..100002] of boolean;
  n,i,k,t:longint;
function p(a,b:longint):longint;
begin
  if (x[a]=x[b])or(y[a]=y[b]) then exit(1);
  p:=maxlongint div 2;
end;
begin
  readln(n,x[1],y[1],x[2],y[2]);
  for i:=3 to n+2 do readln(x[i],y[i]);
  fillchar(d,sizeof(d),63);
  t:=1; s[1]:=1; b[1]:=true; d[1]:=0;
  while t>0 do
  begin
    k:=s[t]; b[k]:=false;
    dec(t);
    for i:=2 to n+2 do
      if d[i]>d[k]+p(k,i) then
      begin
        d[i]:=d[k]+p(k,i);
        if not b[i] then
        begin
          inc(t); s[t]:=i; b[i]:=true;
        end;
      end;
  end;
  writeln(d[2]-1);
end.
