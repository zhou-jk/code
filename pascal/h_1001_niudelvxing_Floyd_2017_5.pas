program h_1001_niudelvxing_Floyd_2017_5_20;
var
  x,y,b:array[1..150] of longint;
  w:array[1..150,0..149] of byte;
  g:array[1..150,1..150] of real;
  max:array[1..150] of real;
  n,i,j,k,m:longint;
  ans,num:real;
  r:string;
procedure dfs(k:byte);
var i:byte;
begin
  b[k]:=m;
  for i:=1 to w[k,0] do
    if b[w[k,i]]=0 then dfs(w[k,i]);
end;
begin
  readln(n);
  for i:=1 to n do readln(x[i],y[i]);
  fillchar(g,sizeof(g),127);
  fillchar(num,sizeof(num),127);
  for i:=1 to n do g[i,i]:=0;
  for i:=1 to n do
  begin
    readln(r);
    for j:=i+1 to n do
      if r[j]='1' then
      begin
        g[i,j]:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])); g[j,i]:=g[i,j];
        inc(w[i,0]); w[i,w[i,0]]:=j;
        inc(w[j,0]); w[j,w[j,0]]:=i;
      end;
  end;
  for i:=1 to n do
   if b[i]=0 then
   begin
     inc(m);
     dfs(i);
   end;
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if g[i,k]+g[k,j]<g[i,j] then g[i,j]:=g[i,k]+g[k,j];
  for i:=1 to n do
    for j:=1 to n do
      if (g[i,j]<num)and(g[i,j]>max[i]) then max[i]:=g[i,j];
  ans:=maxlongint;
  for i:=1 to n do
    for j:=i+1 to n do
      if (b[i]<>b[j])and(max[i]+max[j]+sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))<ans) then ans:=max[i]+max[j]+sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
  writeln(ans:0:6);
end.

