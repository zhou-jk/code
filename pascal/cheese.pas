var
  f:array[0..100000] of int64;
  n,k:int64;
  i,j:longint;
function min(a,b:int64):int64;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  assign(input,'cheese.in'); assign(output,'cheese.out');
  reset(input); rewrite(output);
  readln(n,k);
  for i:=1 to n do
  begin
    f[i]:=i;
    for j:=1 to min(k,i) do f[i]:=f[i]+f[i-j];
	if f[i]>=1234567890 then break;
  end;
  writeln(f[i]);
  close(input); close(output);
end.