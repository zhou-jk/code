var
  s1:array[-10000..10000] of char;
  m,l,r,k,i,j,n:longint;
  s:ansistring;
begin
  assign(input,'shift.in'); assign(output,'shift.out');
  reset(input); rewrite(output);
  readln(s);
  readln(m);
  for i:=1 to m do
  begin
    readln(l,r,k);
    n:=r-l+1; k:=k mod n;
    for j:=l to r do
    begin
      s1[j]:=s[j]; s1[j-n]:=s[j];
    end;
    for j:=l to r do s[j]:=s1[j-k];
  end;
  writeln(s);
  close(input); close(output);
end.
