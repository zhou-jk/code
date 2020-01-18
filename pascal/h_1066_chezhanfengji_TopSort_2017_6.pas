program h_1066_chezhanfengji_TopSort_2017_6_10;
var
  t,t1,stack,ind,a:array[0..1000] of integer;
  g:array[1..1000,1..1000] of boolean;
  vis:array[1..1000] of boolean;
  n,m,s,i,j,k,ans:integer;
begin
  readln(n,m);
  for i:=1 to m do
  begin
    read(s); t1[0]:=0;
    for j:=1 to s do read(t[j]);
    for j:=1 to s-1 do
      for k:=t[j]+1 to t[j+1]-1 do
      begin
        inc(t1[0]);
        t1[t1[0]]:=k;
      end;
    for j:=1 to s do
      for k:=1 to t1[0] do g[t[j],t1[k]]:=true;
  end;
  for i:=1 to n do
  begin
    for j:=1 to n do
      if g[i,j] then
      begin
        inc(ind[j]);
        //write(ind[j],' ');
      end;
    //writeln;
  end;
  for i:=1 to n do
    if ind[i]=0 then
    begin
      inc(stack[0]);
      stack[stack[0]]:=i; vis[i]:=true; a[i]:=1;
    end;
  ans:=1;
  while stack[0]>0 do
  begin
    k:=stack[stack[0]];
    dec(stack[0]);
    for i:=1 to n do
      if g[k,i] then
      begin
        dec(ind[i]);
        //writeln(ind[i]);
        if a[k]>=a[i] then a[i]:=a[k]+1;
        if ind[i]=0 then
        begin
          inc(stack[0]);
          stack[stack[0]]:=i; vis[i]:=true;
          if a[i]>ans then ans:=a[i];
        end;
      end;
  end;
  writeln(ans);
end.
