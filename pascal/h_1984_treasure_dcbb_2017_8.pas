program h_1984_treasure_dcbb_2017_8_17;
var
  n,sw,tv,tw,tm,t,t1,i,j:longint;
  v,w:array[1..1600] of longint;
  f:array[0..40000] of longint;
  s:array[1..16] of longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure new(tv,tw:longint);
begin
  inc(t);
  v[t]:=tv; w[t]:=tw;
end;
begin
  read(n,sw);
  s[1]:=1;
  for i:=2 to 16 do s[i]:=s[i-1]*2;
  for i:=1 to n do
  begin
    read(tv,tw,tm);
    t1:=1;
    while tm>=s[t1] do
    begin
      dec(tm,s[t1]);
      new(s[t1]*tv,s[t1]*tw);
      inc(t1);
    end;
    if tm>0 then new(tm*tv,tm*tw);
  end;
  for i:=1 to t do
    for j:=sw downto w[i] do f[j]:=max(f[j],f[j-w[i]]+v[i]);
  write(f[sw]);
end.