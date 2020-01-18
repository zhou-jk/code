program h_1708_hebingguozi_dui_2017_7_24;
var
  num:array[1..20000] of integer;
  a:array[1..10000] of longint;
  n,i,t,t1,t2,max,ans:longint;
function min(k1,k2:integer):integer;
begin
  if (k2>t)or(a[k1]<a[k2]) then exit(k1);
  exit(k2);
end;
procedure swap(var k1,k2:integer);
var t:longint;
begin
  t:=a[k1]; a[k1]:=a[k2]; a[k2]:=t;
end;
procedure up(k:integer);
var f:integer;
begin
  f:=k div 2;
  while (k>1)and(a[f]>a[k]) do
  begin
    swap(f,k);
    k:=f; f:=k div 2;
  end;
end;
procedure down(k:integer);
var s:integer;
begin
  while 2*k<=t do
  begin
    s:=min(2*k,2*k+1);
    if a[s]<a[k]
    then begin
           swap(s,k);
           k:=s;
         end
    else exit;
  end;
end;
procedure del;
begin
  a[1]:=a[t];
  dec(t);
  down(1);
end;
procedure add_(u:longint);
begin
  inc(t);
  a[t]:=u;
  up(t);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    inc(num[a[i]]);
    if a[i]>max then max:=a[i];
  end;
  for i:=1 to max do
    while num[i]>0 do
    begin
      inc(t);
      a[t]:=i;
      dec(num[i]);
    end;
  while t>1 do
  begin
    t1:=a[1];
    del;
    t2:=t1+a[1];
    del;
    add_(t2);
    ans:=ans+t2;
  end;
  writeln(ans);
end.
