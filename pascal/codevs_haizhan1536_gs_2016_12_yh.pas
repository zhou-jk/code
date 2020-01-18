program codevs_haizhan1536_guanshui_2016_12_4_yh;
uses math;
const
  dx:array[1..4] of integer=(1,0,0,-1);
  dy:array[1..4] of integer=(0,1,-1,0);
var
  m:array[1..1001,1..1001] of char;
  b:array[1..1000,1..1000] of boolean;
  r,c,i,j,ans,l,r1,o,u,num:longint;
procedure dfs(x,y:integer);
var
  i,tx,ty:longint;
begin
  b[x,y]:=true;
  inc(num);
  l:=min(l,y); r1:=max(r1,y); o:=min(o,x); u:=max(u,x);
  for i:=1 to 4 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx>0)and(tx<=r)and(ty>0)and(ty<=c)and not b[tx,ty] and(m[tx,ty]='#') then dfs(tx,ty);
  end;
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
        l:=10000; r1:=0; o:=10000; u:=0; num:=0;
        dfs(i,j);
        if (r1-l+1)*(u-o+1)>num then begin writeln('Bad placement.'); exit; end;
        inc(ans);
      end;
  writeln('There are ',ans,' ships.');
end.

