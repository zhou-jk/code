program codevs_1025_xuancai_01beibao_2017_2_21;
uses math;
var
  f:array[0..1000] of integer;
  d,d1,z:array[1..100] of integer;
  b:array[1..100] of boolean;
  t,t1:array[1..100] of real;
  n,k,i,j,z1,ans:integer;
  x:real;
begin
  readln(n,k,x);
  for i:=1 to n do read(t[i]);
  for i:=1 to n do read(d[i]);
  for i:=1 to n do
  begin
    read(z[i]);
    t1[z[i]]:=t[i];
    d1[z[i]]:=d[i];
  end;
  for i:=1 to k do
  begin
    read(z1);
    b[z1]:=true;
    x:=x-t1[z1];
    inc(ans,d1[z1]);
  end;
  for i:=1 to n do
    if not b[z[i]] then
    begin
      b[z[i]]:=true;
      for j:=trunc(x*10) downto trunc(t[i]*10) do f[j]:=max(f[j],f[j-trunc(t[i]*10)]+d[i]);
    end;
  writeln(f[trunc(x*10)]+ans);
end.


