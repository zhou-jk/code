program nemo5;
{for case 4/10}
const zero=1e-10;
      max=10000000;
type
  ty1=record
    w,x,y,p,q:extended;
  end;
  ty2=record
    t,x,y:extended;
    s:longint;
  end;
var
  v,w0,x0,y0,tot_t,all,x,y:extended;
  n,tot,i,tot_s,t:longint;
  fish:array[0..10000] of ty1;
  step,tmp:array[0..10000] of ty2;
  get:array[0..10000] of boolean;
  sx:array[0..10000] of longint;
  s:array[0..10000] of extended;
//==============================
procedure sort(l,r:longint);
var
  i,j,tmp1:longint;
  tmp2,m:extended;
begin
  i:=l; j:=r; m:=s[(i+j) >> 1];
  repeat
    while s[i]>m do inc(i);
    while s[j]<m do dec(j);
    if i<=j then
    begin
      tmp1:=sx[i]; sx[i]:=sx[j]; sx[j]:=tmp1;
      tmp2:=s[i]; s[i]:=s[j]; s[j]:=tmp2;
      inc(i); dec(j);
    end;
  until i>j;
  if i<r then sort(i,r);
  if j>l then sort(l,j);
end;
//==============================
function calc(t:longint; x,y,now:extended):extended;
var
  fx,fy,a,b,c,d,k:extended;
begin
  k:=max;
  fx:=fish[t].x+now*fish[t].p;
  fy:=fish[t].y+now*fish[t].q;
  a:=sqr(v)-sqr(fish[t].p)-sqr(fish[t].q);
  b:=2*fish[t].p*(x-fx)+2*fish[t].q*(y-fy);
  c:=-sqr(x-fx)-sqr(y-fy);
  if abs(a)<zero then
  begin
    if abs(b)<zero then exit(k);
    if -c/b>-zero then k:=-c/b;
  end else
  begin
    if sqr(b)-4*a*c<-zero then exit(k);
    d:=(-b+sqrt(sqr(b)-4*a*c))/(2*a);
    if d>-zero then k:=d;
    d:=(-b-sqrt(sqr(b)-4*a*c))/(2*a);
    if (d>-zero)and(d>k) then k:=d;
  end;
  exit(k);
end;
//==============================
procedure insert(fx:longint; now:extended);
begin
  inc(tot_s);
  s[tot_s]:=fish[fx].w/sqr(sqr(calc(fx,x,y,now)));
  sx[tot_s]:=fx;
end;
//==============================
function get_rand:longint;
var
  i,j,k:longint;
begin
  for j:=1 to tot_s do
  if (s[j]-s[j+1])/s[j]>0.031 then break;
  for k:=1 to j do
  if random(maxlongint) and 1=1 then break;
  for i:=1 to k do
  begin
    if random() < exp(-10/t) then break;
  end;
  exit(sx[i]);
end;
//==============================
procedure main;
var
  now,w,turn:extended;
  now_tot,t,j,i:longint;
begin
  fillchar(get,sizeof(get),0);
  fillchar(tmp,sizeof(tmp),0);
  now:=0; now_tot:=0; x:=x0; y:=y0; w:=w0;
  for j:=1 to n do
  begin
    tot_s:=0;
    for i:=1 to n do
    if not get[i] and(fish[i].w-w<-zero) then insert(i,now);
    sort(1,tot_s);
    if tot_s<1 then break;
    t:=get_rand;
    turn:=calc(t,x,y,now);
    if turn>max-1000 then continue;
    now:=now+turn;
    if now-tot_t>zero then break;
    get[t]:=true;
    inc(now_tot);
    tmp[now_tot].x:=fish[t].x+fish[t].p*now;
    tmp[now_tot].y:=fish[t].y+fish[t].q*now;
    tmp[now_tot].s:=t;
    tmp[now_tot].t:=now;
    x:=tmp[now_tot].x; y:=tmp[now_tot].y;
    w:=w+fish[t].w;
  end;
  if w>all then
  begin
    tot:=now_tot;
    all:=w;
    step:=tmp;
  end;
end;
//==============================
begin
  assign(input,'nemo10.in'); reset(input);
  assign(output,'nemo10.out'); rewrite(output);
  randomize;
  read(w0,v,tot_t,x0,y0);
  read(n); all:=all+w0;
  for i:=1 to n do read(fish[i].w,fish[i].x,fish[i].y,fish[i].p,fish[i].q);
  t:=20;
  while t>0 do
  begin
    main;
    dec(t);
  end;
  writeln(tot);
  writeln(all-w0:0:6);
  for i:=1 to tot do
  writeln(step[i].t:0:6,' ',step[i].x:0:6,' ',step[i].y:0:6,' ',step[i].s);
  close(input); close(output);
end.