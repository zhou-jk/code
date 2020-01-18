var
  a:array[1..100] of string;
  b1,b2:array[1..8] of longint;
  n,m,i1,i2,j,x,y,c,d:longint;
begin
  readln(n,m);
  for i1:=1 to n do
    readln(a[i1]);
  b1[1]:=-1;  b1[2]:=-1;  b1[3]:=-1;  b1[4]:=0;
  b1[5]:=0;  b1[6]:=1;  b1[7]:=1;  b1[8]:=1;
  b2[1]:=-1;   b2[2]:=0;   b2[3]:=1;  b2[4]:=-1;
  b2[5]:=1;  b2[6]:=-1;  b2[7]:=0;  b2[8]:=1;
  for i1:=1 to n do
    for j:=1 to m do
      if a[i1,j]<>'*' then
        begin
          c:=0;
          for i2:=1 to 8 do
            begin
              x:=i1+b1[i2];  y:=j+b2[i2];
              if (x>0) and (y>0) and (x<=n) and (y<=m) then
                if a[x,y]='*' then
                  inc(c);
            end;
          write(c);
          inc(d);
          if d mod m=0 then
            writeln;
        end
      else
        begin
          write('*');
          inc(d);
          if d mod m=0 then
            writeln;
        end;
  readln;
end.