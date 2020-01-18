var
  s:array[1..500000] of longint;
  n,a,b,t,i,l:longint;
function max(k1,k2:longint):longint;
begin
  if (k2>l)or(s[k1]>s[k2]) then exit(k1);
  exit(k2);
end;
procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a; a:=b; b:=t;
end;
procedure up(k:longint);
var f:longint;
begin
  f:=k div 2;
  while (k>1)and(s[f]<s[k]) do
  begin
    swap(s[f],s[k]);
    k:=f; f:=k div 2;
  end;
end;
procedure down(k:longint);
var son:longint;
begin
  while k<=l div 2 do
  begin
    son:=max(2*k,2*k+1);
    if s[son]>s[k]
    then begin
           swap(s[son],s[k]);
           k:=son;
         end
    else exit;
  end;
end;
procedure add_(n:longint);
begin
  inc(l);
  s[l]:=n;
  up(l);
end;
begin
  assign(input,'dry.in'); assign(output,'dry.out');
  reset(input); rewrite(output);
  read(n,a,b);
  for i:=1 to n do
  begin
    read(t);
    add_(t);
  end;
  t:=0;
  while s[1]>t do
  begin
    dec(s[1],b); inc(t,a);
    down(1);
  end;
  writeln(t div a);
  close(input); close(output);
end.
