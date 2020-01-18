program h_1243_chenjizuida_DP_2017_3_18;
var
  a:array[1..40,1..40]of int64;
  f:array[1..40,1..6] of int64;
  n,m,i,j,k:integer;
  s:string;
function max(a,b:int64):int64;
begin
  if a>b then exit(a);
  max:=b;
end;
begin
  readln(n,m);
  inc(m);
  readln(s);
  for i:=1 to n do
  begin
    for j:=i to n do val(copy(s,i,j-i+1),a[i,j]);
    f[i,1]:=a[1,i];
    for j:=2 to i do
    begin
      if j>m then break;
      for k:=1 to i-j+1 do f[i,j]:=max(f[i-k,j-1]*a[i-k+1,i],f[i,j]);
    end;
  end;
  writeln(f[n,m]);
end.


