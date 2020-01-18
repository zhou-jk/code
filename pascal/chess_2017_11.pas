const
  dx:array[1..4] of longint=(-1,1,0,0);
  dy:array[1..4] of longint=(0,0,-1,1);
var
  gx,gy,l:array[1..100,1..100,1..4] of longint;
  c,d,t:array[1..100,1..100] of longint;
  v:array[1..100,1..100] of boolean;
  m,n,x,y,i,j,k,tx,ty,tx1,ty1,e,top:longint;
  sx,sy:array[1..10000] of longint;
begin
  assign(input,'chess.in'); assign(output,'chess.out');
  reset(input); rewrite(output);
  read(m,n);
  fillchar(c,sizeof(c),255);
  for i:=1 to n do read(x,y,c[x,y]);
  for i:=1 to m do
    for j:=1 to m do
      if c[i,j]>-1
      then for k:=1 to 4 do
           begin
             tx:=i+dx[k]; ty:=j+dy[k];
             if (tx>0)and(tx<=m)and(ty>0)and(ty<=m) then
             begin
               inc(t[i,j]);
               gx[i,j,t[i,j]]:=tx; gy[i,j,t[i,j]]:=ty;
               if c[tx,ty]>-1
               then l[i,j,t[i,j]]:=abs(c[i,j]-c[tx,ty])
               else l[i,j,t[i,j]]:=2;
             end;
           end
      else for k:=1 to 4 do
           begin
             tx:=i+dx[k]; ty:=j+dy[k];
             if (tx>0)and(tx<=m)and(ty>0)and(ty<=m)and(c[tx,ty]>-1) then
             begin
               inc(t[i,j]);
               gx[i,j,t[i,j]]:=tx; gy[i,j,t[i,j]]:=ty;
             end;
           end;
  fillchar(d,sizeof(d),127); fillchar(e,sizeof(e),127);
  d[1,1]:=0; top:=1; sx[1]:=1; sy[1]:=1;
  while top>0 do
  begin
    tx:=sx[top]; ty:=sy[top]; v[tx,ty]:=false;
	//writeln(tx,' ',ty,' ',d[tx,ty],' ',t[tx,ty]);
    dec(top);
    for i:=1 to t[tx,ty] do
    begin
      tx1:=gx[tx,ty,i]; ty1:=gy[tx,ty,i];
      if d[tx,ty]+l[tx,ty,i]<d[tx1,ty1] then
      begin
        d[tx1,ty1]:=d[tx,ty]+l[tx,ty,i];
        if not v[tx1,ty1] then
        begin
          v[tx1,ty1]:=true;
          inc(top);
          sx[top]:=tx1; sy[top]:=ty1;
          if c[tx1,ty1]=-1 then
            for j:=1 to t[tx1,ty1] do
              l[tx1,ty1,j]:=abs(c[gx[tx1,ty1,j],gy[tx1,ty1,j]]-c[tx,ty]);
        end;
      end;
    end;
  end;
  if d[m,m]=e
  then write(-1)
  else write(d[m,m]);
  close(input); close(output);
end.