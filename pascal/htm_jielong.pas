var
  i,n,k_:longint;
  a:ansistring;
function jl(k:longint):ansistring;
begin
  if k=0 then begin jl:='moo'; exit; end;
  a:=jl(k-1);
  jl:=a+'m';
  for i:=1 to k+2 do
    jl:=jl+'o';
  jl:=jl+a;
end;
begin
  readln(n);
  i:=3;
  while i<n do
  begin
    inc(k_);
    i:=i+k_+3+i;
  end;
  a:=jl(k_);
  writeln(a[n]);
  readln;
end.



