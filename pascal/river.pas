var
  s,f:array[0..5000] of longint;
  n,m,m_,i,j:longint;
begin
  assign(input,'river.in'); assign(output,'river.out');
  reset(input); rewrite(output);
  read(n,m);
  s[0]:=m*2;
  for i:=1 to n do
  begin
    read(m_);
    s[i]:=s[i-1]+m_;
  end;
  fillchar(f,sizeof(f),127);
  f[0]:=-10;
  for i:=1 to n do
    for j:=0 to i-1 do
      if f[j]+s[i-j]<f[i] then f[i]:=f[j]+s[i-j];
  write(f[n]);
  close(input); close(output);
end.

