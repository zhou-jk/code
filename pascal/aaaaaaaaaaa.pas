var i,j,n,tot:longint;
    m:int64;
    s1:string;
    sum:array[0..100,0..100]of int64;
    a,b:array[0..9]of longint;
    f:array[0..100]of int64;
procedure js;
var s,he:int64;
    i,j,k:longint;
begin
 he:=-m;
 //writeln('&',he);
 for j:=1 to n do
 for i:=1 to 9 do {begin} he:=he+sum[j,i]*a[i]*f[n-1]; {writeln('$',sum[j,i],' ',a[i],' ',f[n-1]); end;}
 //writeln('#',he);
 inc(tot);
 s:=he;
 if he<0 then exit;
 str(s,s1);
 he:=1;
 fillchar(b,sizeof(b),0);

 for i:=1 to length(s1)do  inc(b[ord(s1[i])-48]);

 for i:=1 to 9 do if a[i]<>b[i] then
 begin
   he:=0;  k:=i;
 end;
 if (he=1) and (length(s1)<=n) then
  begin
    while length(s1)<n do s1:='0'+s1;
    writeln(s1);
  end;
end;
procedure dfs1(x,y:longint);
var i:longint;
begin
 if y=0 then
  begin
   js;
   exit;
  end;
 if x=9 then
  begin
   a[x]:=y;
   dfs1(10,0);
   a[x]:=0;
   exit;
  end;
 for i:=0 to y do
  begin
   a[x]:=i;
   dfs1(x+1,y-i);
   a[x]:=0;
  end;
end;
begin
 //assign(output,'aaaaa.out');
 //rewrite(output);
 readln(n);
 readln(m);
 f[0]:=1;
 for i:=1 to n do f[i]:=f[i-1]*i;
 writeln('%',f[n-1]);
 for i:=0 to 9 do
  sum[1,i]:=i;
 for i:=2 to n do
  for j:=0 to 9 do
   sum[i,j]:=sum[i-1,j]*10;
 dfs1(0,n);
 //close(output);
end.
