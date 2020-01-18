program h_1057_jiapushu_topsort_2017_5_20;
var
  g:array[1..100,0..99] of byte;
  into,s:array[1..100] of byte;
  n,i,j,t,k:byte;
begin
  readln(n);
  for i:=1 to n do
    repeat
      read(t);
      if t>0 then
      begin
        inc(g[i,0]); inc(into[t]);
        g[i,g[i,0]]:=t;
      end;
    until t=0;
  for i:=1 to n do
    if into[i]=0 then
    begin
      inc(t);
      s[t]:=i;
    end;
  for i:=1 to n do
  begin
    k:=s[t];
    dec(t);
    for j:=1 to g[k,0] do
    begin
      dec(into[g[k,j]]);
      if into[g[k,j]]=0 then
      begin
        inc(t);
        s[t]:=g[k,j];
      end;
    end;
    if i<n
    then write(k,' ')
    else write(k);
  end;
end.
