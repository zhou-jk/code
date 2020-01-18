program h_1058_jiangjin_SPFA_2017_5_20;
var
  head,dist,ind,stack,cnt:array[1..10000] of integer;
  n,m,a,b,i,nedge,top,k,t,j,ans:longint;
  p,next:array[1..20000] of integer;
  vis:array[1..10000] of boolean;
begin
  readln(n,m);
  for i:=1 to m do
  begin
    readln(a,b);
    inc(nedge);
    p[nedge]:=a; next[nedge]:=head[b]; head[b]:=nedge;
    inc(ind[a]);
  end;
  for i:=1 to n do
  begin
    if ind[i]=0 then dist[i]:=100;
    stack[i]:=i; vis[i]:=true;
  end;
  top:=n;
  while top>0 do
  begin
    k:=stack[top];
    dec(top);
    vis[k]:=false; t:=head[k];
    while t>0 do
    begin
      j:=p[t];
      if dist[j]<dist[k]+1 then
      begin
        dist[j]:=dist[k]+1;
        if not vis[j] then
        begin
          vis[j]:=true;
          inc(top); stack[top]:=j;
          inc(cnt[j]);
          if cnt[j]>n then
          begin
            writeln('Poor Xed');
            exit;
          end;
        end;
      end;
      t:=next[t];
    end;
  end;
  for i:=1 to n do inc(ans,dist[i]);
  writeln(ans);
end.

