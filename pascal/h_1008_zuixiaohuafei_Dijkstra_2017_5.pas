program h_1008_zuixiaohuafei_SPFA_2017_5_20;
var
  g:array[1..2000,0..1999] of longint;
  z:array[1..2000,1..2000] of double;
  v:array[1..2000] of boolean;
  n,m,x,y,a,b,i,j,t:longint;
  d:array[1..2000] of double;
begin
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y,t);
    inc(g[x,0]); inc(g[y,0]);
    g[x,g[x,0]]:=y; g[y,g[y,0]]:=x; z[x,y]:=1-t/100; z[y,x]:=1-t/100;
  end;
  readln(a,b);
  d[a]:=1000;
  for i:=1 to n do
  begin
    //writeln('i ',i);
    t:=-1;
    for j:=1 to n do
      if not v[j]and((t=-1)or(d[j]>d[t])) then t:=j;
    if t=-1 then break;
    v[t]:=true;
    //writeln(t,' ',d[t]);
    for j:=1 to g[t,0] do
    begin
      //writeln(g[t,j],' ',d[g[t,j]],' ',d[t]*z[t,g[t,j]],'#',z[t,g[t,j]]);
      if not v[g[t,j]]and(d[t]*z[t,g[t,j]]>d[g[t,j]]) then d[g[t,j]]:=d[t]*z[t,g[t,j]];
    end;
  end;
  //writeln('%');
  writeln(100000/d[b]:0:8);
end.
