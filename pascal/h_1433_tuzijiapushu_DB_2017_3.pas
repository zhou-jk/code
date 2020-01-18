program h_1433_tuzijiapushu_DB_2017_3_25;
var
  f:array[1..100,1..200,1..200]of qword;
  c1:array[0..200,0..200]of qword;
  n,k,x1,x2,i,j,p,q,ans:longint;
{function c(n,m:longint):qword;
var i,j:longint;
begin
  if c1[n,m]>0 then exit(c1[n,m]);
  c:=n-m+1; j:=1;
  for i:=n-m+2 to n do
  begin
    inc(j);
    writeln('#',i,' ',j,' ',c);
    if i=n
    then if c mod j=0
         then c:=(c div j)mod 9901*i
         else if i mod j=0
              then c:=(i div j)mod 9901*c
              else c:=i*c div j
    else if c mod j=0
         then c:=c div j*i
         else if i mod j=0
              then c:=i div j*c
              else c:=i*c div j;
  end;
  writeln('*');
  c:=c mod 9901; c1[n,m]:=c;
  writeln('#');
end;}
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  min:=b;
end;
begin
  readln(n,k);
  for i:=1 to n do
  begin
    c1[0,i]:=1; c1[i,0]:=1;
  end;
  for i:=1 to n do
    for j:=1 to n do c1[i,j]:=(c1[i-1,j]+c1[i-1,j-1])mod 9901;
  x1:=1; x2:=2; f[1,1,1]:=1;
  for i:=1 to k-1 do
  begin
    for j:=1 to x2-1 do
      for p:=1 to min(x1,j) do
        if ((i=1)or(p mod 2=0))and(f[i,j,p]>0) then
          for q:=1 to p do
          begin
            if j+q*2>n then break;
            //writeln(i,' ',j,' ',p,' ',q);
            f[i+1,j+q*2,q*2]:=(f[i+1,j+q*2,q*2]+c1[p,q]*f[i,j,p])mod 9901;
          end;
    x1:=min(n,x1*2); x2:=min(n+1,x2*2);
  end;
  for i:=1 to x1 do ans:=(ans+f[k,n,i])mod 9901;
  writeln(ans);
end.
