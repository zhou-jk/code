program codevs_haizhan1536_guanshui_2016_12_4;
uses math;
type
  arr=array[1..5] of longint;
const
  dx:array[1..4] of integer=(1,0,0,-1);
  dy:array[1..4] of integer=(0,1,-1,0);
var
  m:array[1..1001,1..1001] of char;
  b:array[1..1000,1..1000] of boolean;
  r,c,i,j,ans:longint;
  a:arr;
function dfs(x,y:integer):arr;
var
  a:arr;
  k,tx,ty,num,l,o,u,r1:longint;
begin
  b[x,y]:=true;
  num:=1;
  l:=y; r1:=y; o:=x; u:=x;
  for k:=1 to 4 do
  begin
    tx:=x+dx[k]; ty:=y+dy[k];
    if (tx>0)and(tx<=r)and(ty>0)and(ty<=c)and not b[tx,ty] and(m[tx,ty]='#') then
    begin
      a:=dfs(tx,ty); num:=num+a[1]; l:=min(l,a[2]); r1:=max(r1,a[3]); o:=min(o,a[4]); u:=max(u,a[5]);
    end;
  end;
  dfs[1]:=num; dfs[2]:=l; dfs[3]:=r1; dfs[4]:=o; dfs[5]:=u;
end;
begin
  readln(r,c);
  ans:=0;
  for i:=1 to r do
  begin
    for j:=1 to c do read(m[i,j]);
    readln;
  end;
  for i:=1 to r do
    for j:=1 to c do
      if not b[i,j] and(m[i,j]='#') then
      begin
        a:=dfs(i,j);
        if (a[3]-a[2]+1)*(a[5]-a[4]+1)>a[1]  then begin writeln('Bad placement.'); exit; end;
        inc(ans);
      end;
  writeln('There are ',ans,' ships.');
end.

