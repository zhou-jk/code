var
  n,m,i,t1,t2,s1,s2,top:longint;
  s:array[1..30000] of longint;
  st:array[1..210000] of char;
  a1,t:ansistring;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  assign(input,'d.in'); assign(output,'d.out');
  reset(input); rewrite(output);
  read(n,m);
  t1:=1; t2:=1; s[1]:=1; a1:='1';
  for i:=2 to n do
  begin
    s1:=s[t1]<<1+1; s2:=s[t2]<<2+5;
    s[i]:=min(s1,s2);
    if s[i]=s1 then inc(t1);
    if s[i]=s2 then inc(t2);
    str(s[i],t);
	a1:=a1+t;
  end;
  writeln(a1);
  for i:=1 to length(a1) do
  begin
    while (top>0)and(m>0)and(a1[i]>st[top]) do
	begin
	  dec(top); dec(m);
	end;
	inc(top);
	st[top]:=a1[i];
  end;
  for i:=1 to top-m do write(st[i]);
  close(input); close(output);
end.