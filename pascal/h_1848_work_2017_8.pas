program h_1948_work_2017_8_1;
var
  n,i,a,b,max,min,t,l,r,a1,a2:longint;
  w:array[0..1000000] of longint;
  bo:boolean;
begin
  readln(n);
  min:=1000000;
  for i:=1 to n do
  begin
    readln(a,b);
    inc(w[a]); dec(w[b]);
    if a<min then min:=a;
    if b>max then max:=b;
  end;
  r:=min;
  for i:=min to max do
  begin
    t:=t+w[i];
    if not bo and(t>0) then
    begin
      bo:=true;
      l:=i;
      if i-r>a2 then a2:=i-r;
    end;
    if bo and(t=0) then
    begin
      bo:=false;
      r:=i;
      if i-l>a1 then a1:=i-l;
    end;
  end;
  writeln(a1,' ',a2);
end.

