//Tyvj 4749
var
  n,k,m,s,a,b,c,i,t,n1,n2,ans:longint;
  g,l:array[1..300,0..300] of longint;
  d,st,x,v:array[1..300] of longint;
  vis:array[1..300] of boolean;
begin
  read(n,k,m);
  for i:=1 to m do
  begin
    read(a,b,c);
    inc(g[a,0]); g[a,g[a,0]]:=b; l[a,g[a,0]]:=c;
  end;
  read(s);
  filldword(d,300,maxlongint);
  d[s]:=0; t:=1; st[1]:=s; vis[s]:=true;
  while t>0 do
  begin
    n1:=st[t];
    dec(t);
    for i:=1 to g[n1,0] do
    begin
      n2:=g[n1,i];
      if d[n2]>d[n1]+l[n1,i] then
      begin
        d[n2]:=d[n1]+l[n1,i];
        if not vis[n2] then
        begin
          inc(t);
          st[t]:=n2;
          vis[n2]:=true;
        end;
      end;
    end;
    vis[n1]:=false;
  end;
  for i:=1 to k do read(x[i]);
  ans:=1;
  for i:=1 to k do
  begin
    read(v[i]);
    if (d[x[i]]/v[i]<d[x[ans]]/v[ans])or(abs(d[x[i]]/v[i]-d[x[ans]]/v[ans])<1e-7)and(d[x[ans]]<=d[x[i]]) then ans:=i;
  end;
  write(ans);
end.