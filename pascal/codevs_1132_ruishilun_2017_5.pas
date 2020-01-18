program codevs_1132_ruishilun_2017_5_6;
var
  s,w,num,s1,w1,num1:array[1..200000] of longint;
  n,r,q,i,j:longint;
procedure sort(l,r:longint);
var  i,j,x,y,m:longint;
begin
  m:=(l+r) div 2; i:=l; j:=r; x:=s[m];
  repeat
    while (s[i]>x)or(x=s[i])and(num[i]<num[m]) do inc(i);
    while (x>s[j])or(x=s[j])and(num[m]<num[j]) do dec(j);
    if i<=j then
    begin
      if i=m then m:=j else if j=m then m:=i;
      y:=num[i]; num[i]:=num[j]; num[j]:=y;
      y:=s[i]; s[i]:=s[j]; s[j]:=y;
      y:=w[i]; w[i]:=w[j]; w[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
procedure fz(k,m:longint);
begin
  s1[k]:=s[m]; w1[k]:=w[m]; num1[k]:=num[m];
end;
procedure merge;
var
  i,j,k:longint;
begin
  i:=1; j:=1; k:=1;
  while (i<=n)and(j<=n) do
  begin
    if (s[i*2]>s[j*2-1])or(s[i*2]=s[j*2-1])and(num[i*2]<num[j*2-1])
    then begin
           fz(k,i*2);
           inc(i);
         end
    else begin
           fz(k,j*2-1);
           inc(j);
         end;
    inc(k);
  end;
  while i<=n do
  begin
    fz(k,2*i);
    inc(i); inc(k);
  end;
  while j<=n do
  begin
    fz(k,2*j-1);
    inc(j); inc(k);
  end;
  for i:=1 to n do
  begin
    s[i]:=s1[i]; w[i]:=w1[i]; num[i]:=num1[i];
  end;
end;
begin
  readln(n,r,q);
  n:=n*2;
  for i:=1 to n do
  begin
    read(s[i]);
    num[i]:=i;
  end;
  for i:=1 to n do read(w[i]);
  for i:=1 to n-1 do
  sort(1,n);
  for i:=1 to r do
  begin
    for j:=1 to n div 2 do
      if w[j*2]>w[j*2-1]
      then begin
             inc(s[j*2]);
             inc(num[j*2],num[j*2-1]); num[j*2-1]:=num[j*2]-num[j*2-1]; dec(num[j*2],num[j*2-1]);
             inc(s[j*2],s[j*2-1]); s[j*2-1]:=s[j*2]-s[j*2-1]; dec(s[j*2],s[j*2-1]);
             inc(w[j*2],w[j*2-1]); w[j*2-1]:=w[j*2]-w[j*2-1]; dec(w[j*2],w[j*2-1]);
           end;
      if w[j*2]<w[j*2-1] then inc(s[j*2-1]);
    merge;
  end;
  writeln(num[q]);
end.
