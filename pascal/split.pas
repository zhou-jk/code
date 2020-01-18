var
  k,y,a,t:longint;
function gcd(a,b:longint):longint;
begin
  if b=0 then exit(a);
  exit(gcd(b,a mod b));
end;
begin
  assign(input,'split.in'); assign(output,'split.out');
  reset(input); rewrite(output);
  read(k);
  for y:=k*2 downto K+1 do
  begin
    t:=y*k div gcd(y,k);
    if t mod(t div k-t div y)=0 then inc(a);
  end;
  write(a);
  close(input); close(output);
end.
