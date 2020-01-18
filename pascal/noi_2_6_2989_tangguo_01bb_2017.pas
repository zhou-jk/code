program noi_2_6_2989_tangguo_01beibao_2017_2_18;
var
  f,g:array[0..99] of longint;
  a:array[1..100] of longint;
  n,k,i,j,t:longint;
begin
  readln(n,k);
  for i:=1 to n do readln(a[i]);
  g[0]:=0;
  for i:=1 to k-1 do g[i]:=-1;
  for i:=1 to n do
  begin
    for j:=0 to k-1 do
    begin
      f[j]:=g[j];
      t:=g[((j-a[i])mod k+k)mod k];
      if (t>-1)and(t+a[i]>f[j]) then f[j]:=t+a[i];
    end;
    g:=f;
  end;
  writeln(f[0]);
end.


