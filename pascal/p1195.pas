var
  f:array[0..5000] of int64;
  a,b,c:array[0..100000] of int64;
  i,n,m,k:longint;
  ans:int64;
  bo:boolean;
procedure swap(var x,y:int64);
var t:int64;
begin t:=x; x:=y; y:=t; end;
procedure qsort(r,l:longint);
var i,j:longint;
    mid:int64;
begin
  i:=r; j:=l;
  mid:=c[random(j-i+1)+i];
  repeat
    while c[i]<mid do inc(i);
    while c[j]>mid do dec(j);
    if i<=j then
      begin
        swap(a[i],a[j]);
        swap(b[i],b[j]);
        swap(c[i],c[j]);
        inc(i); dec(j);
      end;
  until i>j;
  if i<l then qsort(i,l);
  if r<j then qsort(r,j);
end;//根据路径的长短由小到大快排
function getfather(x:int64):int64;
begin
  if f[x]=x then exit(x) else
    f[x]:=getfather(f[x]);
  exit(f[x]);
end;//并查集路径压缩
begin
  bo:=true;
  randomize;//随机化快排
  read(n,m,k);//读入
  k:=n-k;//求需要合并的步数
  for i:=1 to n do f[i]:=i;
  for i:=1 to m do read(a[i],b[i],c[i]);
  qsort(1,m);//从小到大排，以便后面的贪心选取
  for i:=1 to m do
    begin
      if getfather(a[i])<>getfather(b[i]) then
        begin
          dec(k);//需要的步数-1
          ans:=ans+c[i];//增加最少的代价
          f[getfather(a[i])]:=f[getfather(b[i])];//并集合
          if k=0 then begin bo:=false; break; end;//找到了就标记，并退出循环
        end;
    end;
  if bo then writeln('No Answer') else writeln(ans);//最后的输出
end.