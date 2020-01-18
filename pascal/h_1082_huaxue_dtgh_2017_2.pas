program h_1082_huaxue_dongtaiguihua_2017_2_8;
type ar=array[1..4] of integer;
const
  dx:ar=(-1,0,1,0);
  dy:ar=(0,1,0,-1);
var
  f,a,x,y,b:array[1..10000] of integer;
  r,c,i,j,tx,ty,ans:integer;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure sort(l,r:longint);
var i,j,f,t:longint;
begin
  i:=l; j:=r; f:=a[(l+r) div 2];
  repeat
    while a[i]<f do inc(i);
    while f<a[j] do dec(j);
    if i<=j then
    begin
      t:=a[i]; a[i]:=a[j]; a[j]:=t;
      t:=x[i]; x[i]:=x[j]; x[j]:=t;
      t:=y[i]; y[i]:=y[j]; y[j]:=t;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  readln(r,c);
  for i:=1 to r do
    for j:=1 to c do
    begin
      read(a[(i-1)*c+j]);
      x[(i-1)*c+j]:=i; y[(i-1)*c+j]:=j;
    end;
  b:=a;
  sort(1,r*c);
  //for i:=1 to r*c do writeln(a[i],' ',x[i],' ',y[i]);
  for i:=r*c downto 1 do
  begin
    //writeln('%',i,' ',f[i]);
    for j:=1 to 4 do
    begin
      tx:=x[i]+dx[j]; ty:=y[i]+dy[j];
      if (tx<1)or(ty<1)or(tx>r)or(ty>c)or(b[(tx-1)*c+ty]<=a[i]) then continue;
      //writeln('#',(tx-1)*c+ty,' ',tx,' ',ty,' ',b[(tx-1)*c+ty],' ',f[(tx-1)*c+ty],' ',a[i]);
      f[(x[i]-1)*c+y[i]]:=max(f[(x[i]-1)*c+y[i]],f[(tx-1)*c+ty]);
    end;
    inc(f[(x[i]-1)*c+y[i]]);
    if f[(x[i]-1)*c+y[i]]>ans then ans:=f[(x[i]-1)*c+y[i]];
  end;
  writeln(ans);
end.




