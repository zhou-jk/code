program codevs_3110_erchaduilianxi3_dui_2017_7_24;
var
  a:array[1..500000] of longint;
  n,i:longint;
function min(k1,k2:longint):longint;
begin
  if (k2>n-i)or(a[k1]<a[k2]) then exit(k1);
  exit(k2);
end;
procedure swap(k1,k2:longint);
var t:longint;
begin
  t:=a[k1]; a[k1]:=a[k2]; a[k2]:=t;
end;
procedure up(k:longint);
var f:longint;
begin
  f:=k div 2;
  while (k>1)and(a[f]>a[k]) do
  begin
    swap(k,f);
    k:=f; f:=k div 2;
  end;
end;
procedure down(k:longint);
var s:longint;
begin
  while k<=(n-i)div 2 do
  begin
    s:=min(k*2,k*2+1);
    if a[s]<a[k] then
    begin
      swap(k,s);
      k:=s;
    end
    else exit;
  end;
end;
procedure del;
begin
  a[1]:=a[n-i+1];
  down(1);
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    up(i);
  end;
  for i:=1 to n do
  begin
    write(a[1],' ');
    del;
  end;
end.