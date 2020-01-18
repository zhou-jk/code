type num=array[1..20] of int64;
var
  t,n,i,j,s:longint;
  ans:int64;
{function x(a,b:longint):string;
var
  n:string;
  t,y:int64;
  i:byte;
  n1:num;
begin
  str(a,n);
  for i:=1 to length(n) do val(n[i],n1[length(n)-i+1]);
  for i:=1 to 20 do
  begin
    y:=n1[i]*b+t;
    t:=y div 10;
    y:=y mod 10;
    str(y,x[i]);
    if y>0 then x[0]:=chr(i);
  end;
end;}
begin
  assign(input,'tsum.in'); assign(output,'tsum.out');
  reset(input); rewrite(output);
  readln(t);
  for i:=1 to t do
  begin
    readln(n);
    if n mod 2=0
    then ans:=(1+n)*(n div 2)
    else ans:=(1+n)div 2*n;
    s:=1;
    while s<=n do
    begin
      s:=s shl 1;
      ans:=ans-s;
    end;
    writeln(ans);
  end;
  close(input); close(output);
end.
