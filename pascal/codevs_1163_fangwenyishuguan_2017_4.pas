program codevs_1163_fangwenyishuguan_2017_4_28_x;
var
  h:array[0..100] of record
                       lr:array[1..2] of integer;
                       t,n,tsum:integer;
                     end;
  f:array[1..100,0..600] of integer;
  s,m,i,j,k:integer;
function max(a,b:integer):integer;
begin
  if a>b then exit(a);
  max:=b;
end;
procedure dfsread(k,p:byte);
var m1:byte;
begin
  inc(m);
  h[k].lr[p]:=m;
  read(h[m].t,h[m].n);
  h[m].t:=h[m].t*2+h[m].n*5; h[m].tsum:=h[k].tsum+h[m].t;
  if h[m].n=0 then
  begin
    m1:=m;
    dfsread(m,1); dfsread(m1,2);
  end;
end;
begin
  readln(s);
  dfsread(0,1);
  for i:=m downto 1 do
    with h[i] do
    begin
      if lr[1]=0
      then for j:=t to s-tsum+t do
           begin
             f[i,j]:=n;
             //writeln('#',i,' ',j,' ',n);
           end
      else for j:=0 to s-tsum+t do
             for k:=0 to j-t do
             begin
               f[i,j]:=max(f[i,j],f[lr[1],k]+f[lr[2],j-t-k]);
               //writeln(i,' ',j,' ',lr[1],' ',k,' ',lr[2],' ',j-t-k,' ',f[i,j],' ',f[lr[1],k]+f[lr[2],j-t-k]);
             end;
    end;
  writeln(f[1,s]);
end.
