var
  h,ind,s:array[1..50000] of longint;
  e,ne:array[1..100000] of longint;
  n,m,a,b,i,l,r:longint;
procedure insert(u:word);
begin
  inc(r);
  s[r]:=u;
end;
begin
  assign(input,'money.in'); assign(output,'money.out');
  reset(input); rewrite(output);
  read(n,m);
  for i:=1 to m do
  begin
    read(a,b);
    ne[i]:=h[b]; h[b]:=i; e[i]:=a;
    inc(ind[a]);
  end;
  for i:=1 to n do
    if ind[i]=0 then insert(i);
  while l<r do
  begin
    inc(l);
    write(s[l],' ');
    i:=h[s[l]];
    while i>0 do
    begin
      dec(ind[e[i]]);
      if ind[e[i]]=0 then insert(e[i]);
      i:=ne[i];
    end;
  end;
  close(input); close(output);
end.