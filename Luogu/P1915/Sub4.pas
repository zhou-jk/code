program nemo6;
{for case 5/6}
const zero=1e-10;
type
  ty1=record
    w,x,y,p,q:extended;
  end;
  ty2=record
    t,x,y:extended;
    s:longint;
  end;
var
  v,w0,x0,y0,tot_t,all,best:extended;
  n,tot,i,j,t:longint;
  fish:array[0..10000] of ty1;
  step:array[0..10000] of ty2;
  f,fall:array[0..10000] of extended;
  sa,g:array[0..10000] of longint;
//====================
procedure sort(l,r:longint);
var
  i,j,tmp1:longint;
  tmp2,m:extended;
begin
  i:=l; j:=r; m:=fall[(i+j) >> 1];
  repeat
    while fall[i]<m do inc(i);
    while fall[j]>m do dec(j);
    if i<=j then
    begin
      tmp2:=fall[i]; fall[i]:=fall[j]; fall[j]:=tmp2;
      tmp1:=sa[i]; sa[i]:=sa[j]; sa[j]:=tmp1;
      inc(i); dec(j);
    end;
  until i>j;
  if i<r then sort(i,r);
  if j>l then sort(l,j);
end;
//====================
function check(l,r:longint):boolean;
begin
  if abs(fish[sa[l]].x-fish[sa[r]].x)/v+fall[l]-fall[r]>zero then exit(false);
  exit(true);
end;
//====================
procedure huisu(x:longint);
begin
  if g[x]>0 then huisu(g[x]);
  inc(tot);
  all:=all+fish[sa[x]].w;
  step[tot].s:=sa[x];
  step[tot].x:=fish[sa[x]].x;
  step[tot].t:=fall[x];
end;
//====================
begin
  assign(input,'nemo6.in'); reset(input);
  assign(output,'nemo6.out'); rewrite(output);
  randomize;
  read(w0,v,tot_t,x0,y0);
  read(n); all:=0;
  for i:=1 to n do
  begin
    read(fish[i].w,fish[i].x,fish[i].y,fish[i].p,fish[i].q);
    fall[i]:=abs(fish[i].y-y0)/abs(fish[i].q);
    sa[i]:=i;
  end;
  sort(1,n);
  for i:=1 to n do f[i]:=-100000000;
  f[0]:=0;
  for i:=1 to n do
  begin
    for j:=0 to i-1 do
    if check(j,i) and (f[i]<f[j]+fish[sa[i]].w) then
    begin
      f[i]:=f[j]+fish[sa[i]].w;
      g[i]:=j;
    end;
    if best<f[i] then
    begin
      best:=f[i];
      t:=i;
    end;
  end;
  huisu(t);
  writeln(tot);
  writeln(all:0:6);
  for i:=1 to tot do
  writeln(step[i].t:0:6,' ',step[i].x:0:6,' ',step[i].y:0:6,' ',step[i].s);
  close(input); close(output);
end.