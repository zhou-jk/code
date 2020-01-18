var
  g,b:array[1..1001] of string;
  t1:array[1..3] of string;
  n,i,j,k,tmp,ans:longint;
  s,t:string;
procedure sort(l,r:longint);
var
  i,j:longint;
  x,y:string;
begin
  i:=l; j:=r; x:=g[(l+r)div 2,1];
  repeat
    while g[i,1]<x do inc(i);
    while x<g[j,1] do dec(j);
    if i<=j then
    begin
      y:=g[i]; g[i]:=g[j]; g[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  assign(input,'records.in'); assign(output,'records.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    readln(s);
    k:=0; s:=S+' ';
    for j:=1 to 3 do
    begin
      inc(k); t:='';
      while s[k]<>' ' do
      begin
        t:=t+s[k];
        inc(k);
      end;
      t1[j]:=t;
    end;
    //writeln('%');
    for j:=1 to 2 do
      for k:=j+1 to 3 do
        if t1[j]>t1[k] then
        begin
          t:=t1[j]; t1[j]:=t1[k]; t1[k]:=t;
        end;
    g[i]:=t1[1]+t1[2]+t1[3];
    //writeln(t1[1],' ',t1[2],' ',t1[3]);
  end;
  //writeln('%');
  sort(1,n);
  k:=0;
  for i:=1 to n do
    if g[i]<>g[i+1] then
    begin
      inc(k);
      b[k]:=g[i];
    end;
  //writeln(k);
  for i:=1 to k do
  begin
    tmp:=0;
    for j:=1 to n do
      if g[j]=b[i] then inc(tmp);
    if tmp>ans then ans:=tmp;
  end;
  writeln(ans);
  close(input); close(output);
end.