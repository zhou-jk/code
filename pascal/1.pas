var
  a:array[1..100000] of longint;
  b:array[1..10000] of longint;
  n,m,i,s,t,n1,pos:longint;
begin
  readln(n);
  for i:=1 to n do
    read(a[i]);
  readln(m);
  for i:=1 to m do
    readln(b[i]);
  for i:=1 to m do
    begin
      if b[i]<=a[1] then
        begin
          writeln(a[1]);
          continue;
        end;
      if b[i]>=a[n] then
        begin
          writeln(a[n]);
          continue;
        end;
      s:=1;
      n1:=n;
      while s<=n1 do
        begin
          t:=(s+n1) div 2;
          if b[i]<=a[t] then
            begin
              n1:=t-1; pos:=t;
            end
          else
            s:=t+1;
        end;
      if pos+1<100001 then
        if abs(b[i]-a[pos])>abs(a[pos+1]-b[i]) then
          inc(pos);
      if pos-1<>0 then
        if abs(b[i]-a[pos-1])<=abs(b[i]-a[pos]) then
          pos:=pos-1;
      writeln(a[pos]);
    end;
  readln;
end.