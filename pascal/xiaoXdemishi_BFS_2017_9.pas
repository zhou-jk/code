//PrayerOJ 2005
var
  n,m,k,x,y,i,j,tmp,tmp1,t,l,r:longint;
  d:array[1..5000,0..1023] of integer;
  g,ne,p:array[1..6000] of integer;
  s,b:array[1..5120000] of integer;
  a,h:array[1..5000] of integer;
procedure ae(x,y:integer);
begin
  inc(t);
  g[t]:=y; ne[t]:=h[x]; h[x]:=t; p[t]:=tmp1;
end;
begin
  read(n,m,k);
  for i:=1 to n do
    for j:=1 to k do
    begin
      read(tmp);
      a[i]:=a[i]<<1+tmp;
    end;
  for i:=1 to m do
  begin
    read(x,y);
    tmp1:=0;
    for j:=1 to k do
    begin
      read(tmp);
      tmp1:=tmp1<<1+tmp;
    end;
    ae(x,y);
  end;
  fillchar(d,10240000,255);
  l:=0; r:=1; s[1]:=1; b[1]:=a[1]; d[1,a[1]]:=0;
  while l<r do
  begin
    inc(l); tmp:=h[s[l]];
    while tmp<>0 do
    begin
      tmp1:=b[l]or a[g[tmp]];
      if (b[l]and p[tmp]=p[tmp])and(d[g[tmp],tmp1]=-1) then
      begin
        inc(r); s[r]:=g[tmp]; b[r]:=tmp1; d[g[tmp],tmp1]:=d[s[l],b[l]]+1;
        if g[tmp]=n then
        begin
          write(d[g[tmp],tmp1]);
          close(input); close(output);
          exit;
        end;
      end;
      tmp:=ne[tmp];
    end;
  end;
  write('No Solution');
end.
