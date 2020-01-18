var
  num:array[1..30000] of string[7];
  s:array[1..30000] of longint;
  v:array[1..30000] of boolean;
  n,m,i,j,t1,t2,s1,s2:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  assign(input,'d.in'); assign(output,'d.out');
  reset(input); rewrite(output);
  read(n,m);
  t1:=1; t2:=1; s[1]:=1;
  write(1);
  for i:=2 to n do
  begin
    s1:=s[t1]<<1+1; s2:=s[t2]<<2+5;
    s[i]:=min(s1,s2);
    if s[i]=s1 then inc(t1);
    if s[i]=s2 then inc(t2);
    write(s[i]);
    str(s[i],num[i]);
    j:=i-1;
    while (m>0)and(j>0)and(num[j]<num[i]) do
    begin
      if not v[j] then
      begin
        v[i]:=true;
        dec(m);
      end;
      dec(j);
    end;
  end;
  i:=n;
  while (i>0)and(m>0) do
  begin
    if not v[i] then
    begin
      v[i]:=true;
      dec(m);
    end;
    dec(i);
  end;
  writeln;
  for i:=1 to n do
    if not v[i] then write(s[i]);
  close(input); close(output);
end.