var
  x:array[1..1000,1..3000] of longint;
  f:array[1..1000,1..1000] of boolean;
  t,k,l,ma:array[1..1000] of longint;
  n,i,j,m,ans:longint;
begin
  assign(input,'port.in');
  assign(output,'port.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(t[i],k[i]);
    for j:=1 to k[i] do read(x[i,j]);
  end;
  //writeln('*');
  l[1]:=t[1];
  for i:=1 to k[1] do begin f[1,x[1,i]]:=true; if x[1,i]>ma[1] then ma[1]:=x[1,i]; end;
  for j:=1 to ma[1] do if f[1,j] then inc(ans);
  writeln(ans);
  //writeln('#');
  for i:=2 to n do
  begin
    j:=i;
    while (j-1>0)and(t[j]-l[j-1]<86400) do dec(j);
    if j<i
    then begin
           f[i]:=f[j];
           ma[i]:=ma[j];
           for j:=1 to k[i] do begin f[i,x[i,j]]:=true; if x[i,j]>ma[i] then ma[i]:=x[i,j]; end;
           l[i]:=l[j];
         end
    else begin
           while (j-1>0)and(t[i]-t[j-1]<86400) do
           begin
             dec(j);
             for m:=1 to k[j] do begin f[i,x[j,m]]:=true; if ma[i]<x[j,m] then ma[i]:=x[j,m]; end;
           end;
           l[i]:=t[j];
           for j:=1 to k[i] do begin f[i,x[i,j]]:=true; if ma[i]<x[i,j] then ma[i]:=x[i,j]; end;
         end;
    ans:=0;
    for j:=1 to ma[i] do if f[i,j] then inc(ans);
    writeln(ans);
  end;
  close(input);
  close(output);
end.
