//CodeVS 2123
uses math;
type n=array[0..1000] of longint;
var
  p,len,i,j,t:longint;
  n1,n2,ans:n;
procedure output(num:n);
begin
  for i:=19 downto 0 do
  begin
    for j:=50 downto 1 do write(num[i*50+j]);
    writeln;
  end;
end;
function solve(p:longint):n;
  function multiplication(a,b:n):n;
  begin
    fillchar(multiplication,4004,0);
    for i:=1 to min(a[0],1000) do
      for j:=1 to min(b[0],1001-i) do inc(multiplication[i+j-1],a[i]*b[j]);
    t:=0;
    for i:=1 to min(a[0]+b[0],1000) do
    begin
      inc(multiplication[i],t);
      t:=multiplication[i]div 10;
      multiplication[i]:=multiplication[i]mod 10;
    end;
    while multiplication[i]=0 do dec(i);
    multiplication[0]:=i;
  end;
  function square(num:n):n;
  begin
    exit(multiplication(num,num));
  end;
  function fast_power(p:longint):n;
  begin
    if p=1 then exit(n2);
    fast_power:=square(fast_power(p div 2));
    if p mod 2=1 then exit(multiplication(fast_power,n2));
  end;
  function minus(a,b:n):n;
  begin
    fillchar(minus,4004,0);
    for i:=1 to a[0] do
    begin
      inc(minus[i],a[i]-b[i]);
      if minus[i]<0 then
      begin
        dec(minus[i+1]); inc(minus[i],10);
      end;
    end;
  end;
begin
  len:=trunc(ln(2)/ln(10)*p+1);
  exit(minus(fast_power(p),n1));
end;
procedure define;
begin
  n1[0]:=1; n1[1]:=1; n2[0]:=1; n2[1]:=2;
end;
begin
  read(p);
  define;
  ans:=solve(p);
  writeln(len);
  output(ans);
end.