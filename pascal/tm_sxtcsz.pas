var
  a:array[1..10,1..10] of longint;
  i,j,n,b,c:longint;
  d:boolean;
begin
  readln(n);
  j:=1;
  for i:=1 to n*n do
    if j<=n then
      if j mod 2=0 then
        begin
          if d=false then
            begin
              c:=1; b:=0; d:=true;
            end;
          a[c,j-b]:=i;
          inc(b); inc(c);
          if b=j then
            begin
              inc(j); d:=false;
            end;
        end
      else
        begin
          if d=false then
            begin
              b:=j-1; c:=j; d:=true;
            end;
          a[c,j-b]:=i;
          c:=c-1; b:=b-1;
          if c=0 then
            begin
              inc(j); d:=false;
            end;
        end
    else
      if j mod 2=0 then
        begin
          if d=false then
            begin
              c:=j-n+1; b:=j-n; d:=true;
            end;
          a[c,j-b]:=i;
          inc(c); inc(b);
          if c>n then
            begin
              inc(j); d:=false;
            end;
        end
      else
        begin
          if d=false then
            begin
              c:=n; b:=n+n-1-j; d:=true;
            end;
          a[c,n-b]:=i;
          c:=c-1; b:=b-1;
          if b=-1 then
            begin
              inc(j); d:=false;
            end;
        end;
  for i:=1 to n do
    for j:=1 to n do
      begin
        write(a[i,j],' ');
        if j=n then
          writeln;
      end;
  readln;
end.









