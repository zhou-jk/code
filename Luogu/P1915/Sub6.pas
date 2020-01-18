program nemo;
{for case 9}
const max=10000000;
      zero=1e-6;
type
  ty1=record
    w,x,y,p,q:extended;
  end;
  ty2=record
    t,x,y:extended;
    s:longint;
  end;
var
  w,x,y,v,tot_t,now_t,ans,d:extended;
  n,i,j,t,tot:longint;
  f:array[0..10000] of ty1;
  get:array[0..10000] of boolean;
  step:array[0..10000] of ty2;
//============================
function dis(i:longint; x,y:extended):extended;
begin
  exit(sqrt(sqr(x-f[i].x)+sqr(y-f[i].y)));
end;
//============================
begin
  assign(input,'nemo9.in'); reset(input);
  assign(output,'nemo9.out'); rewrite(output);
  read(w,v,tot_t,x,y);
  read(n); ans:=0; tot:=0; now_t:=0;
  fillchar(get,sizeof(get),false);
  for i:=1 to n do read(f[i].w,f[i].x,f[i].y,f[i].p,f[i].q);
  for i:=1 to n do
  begin
    d:=max; t:=0;
    for j:=1 to n do
    if not get[j] and (f[j].w-w<-zero) and (dis(j,x,y)<d)  then
    begin
      t:=j;
      d:=dis(j,x,y);
    end;
    if t=0 then break;
    now_t:=now_t+dis(t,x,y)/v;
    if now_t-tot_t>zero then break;
    get[t]:=true;
    w:=w+f[t].w;
    ans:=ans+f[t].w;
    inc(tot);
    step[tot].t:=now_t;
    step[tot].s:=t;
    step[tot].x:=f[t].x;
    step[tot].y:=f[t].y;
    x:=f[t].x; y:=f[t].y;
  end;
  writeln(tot);
  writeln(ans:0:6);
  for i:=1 to tot do
  writeln(step[i].t:0:6,' ',step[i].x:0:6,' ',step[i].y:0:6,' ',step[i].s);
  close(input); close(output);
end.