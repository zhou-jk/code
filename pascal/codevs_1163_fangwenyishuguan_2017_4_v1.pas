program codevs_1163_fangwenyishuguan_2017_4_29_v1;
var
  t,n,lc,rc:array[0..100] of integer;
  f:array[1..100,0..600] of integer;
  s,m:integer;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  max:=b;
end;
function min(a,b:integer):integer;
begin
  if a<b then exit(a);
  min:=b;
end;
procedure dr(k:byte);
begin
  read(t[k],n[k]);
  if n[k]=0 then
  begin
    inc(m);
    lc[k]:=m;
    dr(m);
    inc(m);
    rc[k]:=m;
    dr(m);
  end;
end;
procedure solve(k,s:integer);
var i,tmp,lt,rt:integer;
begin
  if f[k,s]>-1 then exit;
  if n[k]>0 then
  begin
    f[k,s]:=min(n[k],s div 5);
    exit;
  end;
  f[k,s]:=0;
  for i:=0 to s do
  begin
    tmp:=0; lt:=i-2*t[lc[k]]; rt:=s-i-2*t[rc[k]];
    if lt>=0 then
    begin
      solve(lc[k],lt);
      inc(tmp,f[lc[k],lt]);
    end;
    if rt>=0 then
    begin
      solve(rc[k],rt);
      inc(tmp,f[rc[k],rt]);
    end;
    f[k,s]:=max(f[k,s],tmp);
  end;
end;
begin
  readln(s);
  m:=1;
  dr(1);
  fillchar(f,sizeof(f),255);
  solve(1,s-2*t[1]);
  writeln(f[1,s-2*t[1]]);
end.
