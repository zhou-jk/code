program h_1244_jinmingdeyusuanfangan_beibao_2017_2_25;
var
  v,w,q:array[1..60] of integer;
  f:array[0..32000] of longint;
  p:array[1..60,0..2] of integer;
  n,m,i,j,t:longint;
procedure pd;
begin
  if t>f[j] then f[j]:=t;
end;
begin
  readln(n,m);
  for i:=1 to m do
  begin
    readln(v[i],w[i],q[i]);
    if q[i]>0 then
    begin
      inc(p[q[i],0]);
      p[q[i],p[q[i],0]]:=i;
    end;
  end;
  for i:=1 to m do
  begin
    if q[i]>0 then continue;
    for j:=n downto v[i] do
    begin
      //writeln('#',i,' ',j);
      t:=f[j-v[i]]+v[i]*w[i];
      pd;
      if (p[i,0]>0)and(v[i]+v[p[i,1]]<=j) then t:=f[j-v[i]-v[p[i,1]]]+v[i]*w[i]+v[p[i,1]]*w[p[i,1]];
      pd;
      //writeln('@');
      if p[i,0]>1 then
      begin
        if v[i]+v[p[i,2]]<=j then t:=f[j-v[i]-v[p[i,2]]]+v[i]*w[i]+v[p[i,2]]*w[p[i,2]];
        pd;
        if v[i]+v[p[i,1]]+v[p[i,2]]<=j then t:=f[j-v[i]-v[p[i,1]]-v[p[i,2]]]+v[i]*w[i]+v[p[i,1]]*w[p[i,1]]+v[p[i,2]]*w[p[i,2]];
        pd;
      end;
    end;
  end;
  writeln(f[n]);
end.


