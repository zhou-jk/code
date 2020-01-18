program htm_1789_jiabi_2017_1_30;
var
  b:array[1..100] of integer;
  a:array[1..100] of record
                       p:byte;
                       l:array[1..50] of byte;
                       r:array[1..50] of byte;
                       c:char;
                     end;
  n,k,i,j,s,po,min:integer;
begin
  readln(n,k);
  for i:=1 to k do
  begin
    read(a[i].p);
    for j:=1 to a[i].p do read(a[i].l[j]);
    for j:=1 to a[i].p do read(a[i].r[j]);
    readln;
    readln(a[i].c);
    if a[i].c='=' then
      for j:=1 to a[i].p do
      begin
        b[a[i].l[j]]:=2; b[a[i].r[j]]:=2;
      end;
  end;
  for i:=1 to k do
    if a[i].c<>'=' then
    begin
      s:=0;
      for j:=1 to a[i].p do
      begin
        if b[a[i].l[j]]<2 then
        begin
          inc(s);
          po:=a[i].l[j];
          dec(b[a[i].l[j]]);
        end;
        if b[a[i].r[j]]<2 then
        begin
          inc(s);
          po:=a[i].r[j];
          dec(b[a[i].r[j]]);
        end;
      end;
      if s=1 then
      begin
        writeln(po);
        exit;
      end;
    end;
  min:=1;
  s:=0;
  po:=0;
  for i:=1 to n do
  begin
    if b[i]=min then
    begin
      inc(s);
      po:=i;
    end;
    if b[i]<min then
    begin
      s:=1;
      po:=i;
      min:=b[i];
    end;
  end;
  if s>1
  then writeln(0)
  else writeln(po);
end.




