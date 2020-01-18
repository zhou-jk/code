var
  f:array[0..100001] of qword;
  k,q,i:longint;
  a,l,r:qword;
begin
  assign(input,'dream.in'); assign(output,'dream.out');
  reset(input); rewrite(output);
  read(k);
  for i:=1 to k do
  begin
    read(a);
    f[i]:=f[i-1]xor a;
  end;
  f[k+1]:=0;
  inc(k);
  read(q);
  for i:=1 to q do
  begin
    read(l,r);
    l:=(l-1)mod k+1; r:=(r-1)mod k+1;
    writeln(f[r]xor f[l-1]);
  end;
  close(input); close(output);
end.