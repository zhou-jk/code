uses math;
type arr=array[1..50] of longint;
var
  n,k,i,m:longint;
  c:string;
function ff(n,k:longint):string;
var
  a,b:arr;
  e,f:string;
  j,t,d:longint;
begin
  t:=0;
  ff:='';
  for i:=1 to 50 do
  begin
    a[i]:=0;
    b[i]:=0;
  end;
  if (n<k)or(k=0)
    then begin
           ff:='0';
           m:=1;
         end
    else if (k=1)or(k=n)
           then begin
                  ff:='1';
                  m:=1;
                end
           else begin
                  e:=ff(n-1,k);
                  f:=ff(n-1,k-1);
                  for i:=1 to length(e) do
                    val(e[i],a[i]);
                  for i:=1 to length(f) do
                    val(f[i],b[i]);
                  d:=length(e);
                  for i:=1 to d do
                  begin
                    a[i]:=a[i]*k+t;
                    t:=a[i] div 10;
                    a[i]:=a[i] mod 10;
                  end;
                  while t>0 do
                  begin
                    inc(i);
                    a[i]:=t mod 10;
                    t:=t div 10;
                    inc(d);
                  end;
                  m:=length(f);
                  for i:=1 to max(d,m) do
                  begin
                    b[i]:=b[i]+a[i]+t;
                    t:=b[i] div 10;
                    b[i]:=b[i] mod 10;
                  end;
                  m:=max(d,m);
                  if t>0 then
                  begin
                    inc(i);
                    b[i]:=t;
                    inc(m);
                  end;
                  for i:=1 to m do
                  begin
                    str(b[i],e);
                    ff:=ff+e;
                  end;
                end;
end;
begin
  readln(n,k);
  c:=ff(n,k);
  for i:=m downto 1 do
    write(c[i]);
  readln;
end.




