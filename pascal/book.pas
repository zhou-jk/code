var
  a,b,f,g:array[1..500]of integer;
  n,i,j,ansf,ansg,c:integer;
procedure sort(l,r:longint);
var  i,j,x,y:longint;
begin
  i:=l; j:=r; x:=a[(l+r) div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if i<=j then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      y:=b[i]; b[i]:=b[j]; b[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  assign(input,'book.in'); assign(output,'book.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do readln(a[i],b[i]);
  sort(1,n);
  f[1]:=b[1]-a[1]+1; g[1]:=1;
  for i:=2 to n do
  begin
    c:=1;
    for j:=1 to i-1 do
    begin
      if (b[j]=a[i]) then
      begin
        c:=0;
        if f[j]>f[i]
        then begin
               f[i]:=f[j]; g[i]:=g[j];
             end
        else if (f[j]=f[i])and(g[j]>g[i]) then g[i]:=g[j];
      end;
    end;
    inc(f[i],b[i]-a[i]+c); inc(g[i]);
    if f[i]>ansf
    then begin
           ansf:=f[i]; ansg:=g[i];
         end
    else if (f[i]=ansf)and(g[i]>ansg) then ansg:=g[i];
  end;
  writeln(ansf,' ',ansg);
  close(input); close(output);
end.

