program htm_1249_chengbao_guanshui_2017_2_3;
type ar=array[0..3] of integer;
const
  dx:ar=(0,-1,0,1);
  dy:ar=(-1,0,1,0);
var
  m,n,i,j,k,num,s,maxs,ax,ay,f:integer;
  b:array[1..50,1..50] of boolean;
  a:array[1..50,1..50] of byte;
procedure dfs(x,y:byte);
var i,tx,ty:byte;
begin
  inc(s);
  b[x,y]:=true;
  for i:=0 to 3 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx<1)or(ty<1)or(tx>n)or(ty>m)or b[tx,ty] or(a[x,y]and(1<<i)>0) then continue;
    dfs(tx,ty);
  end;
end;
begin
  readln(m,n);
  for i:=1 to n do
    for j:=1 to m do read(a[i,j]);
  for i:=1 to n do
    for j:=1 to m do
      if not b[i,j] then
      begin
        inc(num);
        s:=0;
        dfs(i,j);
        if s>maxs then maxs:=s;
      end;
  writeln(num);
  writeln(maxs);
  maxs:=0;
  for i:=1 to m do
    for j:=n downto 1 do
      for k:=1 to 2 do
        if a[j,i]and(1<<k)>0 then
        begin
          fillchar(b,sizeof(b),false);
          a[j,i]:=a[j,i]xor(1<<k); s:=0;
          dfs(j,i);
          a[j,i]:=a[j,i]xor(1<<k);
          if s>maxs then
          begin
            maxs:=s; ax:=j; ay:=i; f:=k;
          end;
        end;
  writeln(maxs);
  write(ax,' ',ay,' ');
  if f=1
  then writeln('N')
  else writeln('E');
end.

