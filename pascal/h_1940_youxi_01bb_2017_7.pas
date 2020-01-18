program h_1940_youxi_01beibao_2017_7_30_n;
var
  f:array[0..40000] of longint;
  s:array[1..200,0..200] of longint;
  x,y,t,v:array[1..200] of longint;
  b:array[1..200] of boolean;
  n,ts,i,j,k,t1,t2:longint;

function pd1(a,b:longint):longint;
begin
  exit((a>=0)and(b>0)or(a<=0)and(b<0)or(a=0)and(b=0));
end;

function pd2(a,b:longint):longint;
begin
  exit();
end;

function pd3(a,b:longint):longint;
begin
  exit();
end;

function pd(k1,k2:longint):boolean;
var a,b,c,d:longint;
begin
  a:=x[k1]; b:=x[k2]; c:=y[k1]; d:=y[k2];
  exit(pd1(a,b)and pd1(c,d)and pd2(a,b)and
end;

procedure swap(var a,b:longint);
var t1:longint;
begin
  t1:=a; a:=b; b:=t1;
end;

procedure sort(l,r:longint);
var i,j,t1,t2:longint;
begin
  i:=l; j:=r; t1:=abs(y[(l+r)div 2]); t2:=abs(x[(l+r)div 2]);
  repeat
    while (abs(y[i])<t1)or(abs(y[i])=t1)and(abs(x[i])<t2) do inc(i);
    while (t1<abs(y[j]))or(abs(y[i])=t1)and(t2<abs(x[i])) do dec(j);
    if i<=j then
    begin
      swap(x[i],x[j]); swap(y[i],y[j]); swap(t[i],t[j]); swap(v[i],v[j]);
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

begin
  readln(n,ts);
  for i:=1 to n do readln(x[i],y[i],t[i],v[i]);
  sort(1,n);
  //for i:=1 to n do writeln(x[i],y[i],t[i],v[i]);
  for i:=1 to n-1 do
    if not b[i] then
      for j:=i+1 to n do
        if pd(i,j) then
        begin
          b[j]:=true;
          inc(s[i,0]);
          s[i,s[i,0]]:=j;
        end;
  for i:=1 to n do
    if not b[i] then
     for j:=ts downto t[i] do
     begin
       //writeln(i,' ',j,' ',t[i],' ',v[i],' ',f[j]);
       if f[j-t[i]]+v[i]>f[j] then f[j]:=f[j-t[i]]+v[i];
       t1:=t[i]; t2:=v[i];
       for k:=1 to s[i,0] do
       begin
         //writeln(k,' ',t1,' ',t2);
         t1:=t1+t[s[i,k]]; t2:=t2+v[s[i,k]];
         //writeln(t1,' ',t2);
         if t1>j then break;
         if f[j-t1]+t2>f[j] then f[j]:=f[j-t1]+t2;
         //writeln(f[j]);
       end;
     end;
  writeln(f[ts]);
end.
