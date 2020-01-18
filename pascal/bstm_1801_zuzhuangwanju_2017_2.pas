program bstm_1801_zuzhuangwanju_2017_2_4;
var
  x,y:array[1..100000] of longint;
  n,m,i,min,max,ans,mid:longint;
function p(s:longint):boolean;
var
  m1,c:longint;
begin
  m1:=m;
  p:=true;
  for i:=1 to n do
  begin
    if x[i] div y[i]<s then
    begin
      c:=y[i]*s-x[i];
      //writeln(i,' ',s);
      dec(m1,c);
    end;
    if m1<0 then exit(false);
  end;
  if m1=0 then
  begin
    writeln(s);
    halt;
  end;
end;
begin
  readln(n,m);
  for i:=1 to n do read(x[i]);
  min:=1000000000;
  for i:=1 to n do
  begin
    read(y[i]);
    if x[i] div y[i]<min then min:=x[i] div y[i];
    if (x[i]+m)div y[i]>max then max:=(x[i]+m)div y[i];
  end;
  //writeln('#',min,' ',max);
  while min<=max do
  begin
    mid:=(min+max)div 2;
    if p(mid)
    then min:=mid+1
    else max:=mid-1;
  end;
  writeln(max);
end.
