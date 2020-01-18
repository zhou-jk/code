type d=array[1..4] of integer;
const
  dx:d=(-1,1,0,0);
  dy:d=(0,0,-1,1);
var
  q:array[1..1000,1..100] of char;
  w,h,i,j,s,a:longint;
procedure dfs(x,y:integer);
var i,tx,ty:integer;
begin
  inc(s);
  q[x,y]:='.';
  for i:=1 to 4 do
  begin
    tx:=x+dx[i]; ty:=y+dy[i];
    if (tx>0)and(tx<=h)and(ty>0)and(ty<=w)and(q[tx,ty]='*') then dfs(tx,ty);
  end;
end;
begin
  assign(input,'b.in'); assign(output,'b.out');
  reset(input); rewrite(output);
  readln(w,h);
  for i:=1 to h do
  begin
    for j:=1 to w do read(q[i,j]);
    readln;
  end;
  {for i:=1 to h do
  begin
    for j:=1 to w do write(q[i,j]);
    writeln;
  end;}
  for i:=1 to h do
    for j:=1 to w do
      if q[i,j]='*' then
      begin
        s:=0;
        dfs(i,j);
        //writeln(i,' ',j,' ',s);
        if s>a then a:=s;
      end;
  write(a);
  close(input); close(output);
end.
