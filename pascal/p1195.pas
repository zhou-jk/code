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
end;//����·���ĳ�����С�������
function getfather(x:int64):int64;
begin
  if f[x]=x then exit(x) else
    f[x]:=getfather(f[x]);
  exit(f[x]);
end;//���鼯·��ѹ��
begin
  bo:=true;
  randomize;//���������
  read(n,m,k);//����
  k:=n-k;//����Ҫ�ϲ��Ĳ���
  for i:=1 to n do f[i]:=i;
  for i:=1 to m do read(a[i],b[i],c[i]);
  qsort(1,m);//��С�����ţ��Ա�����̰��ѡȡ
  for i:=1 to m do
    begin
      if getfather(a[i])<>getfather(b[i]) then
        begin
          dec(k);//��Ҫ�Ĳ���-1
          ans:=ans+c[i];//�������ٵĴ���
          f[getfather(a[i])]:=f[getfather(b[i])];//������
          if k=0 then begin bo:=false; break; end;//�ҵ��˾ͱ�ǣ����˳�ѭ��
        end;
    end;
  if bo then writeln('No Answer') else writeln(ans);//�������
end.