//PrayerOJ 2082
var
  t:array[0..1000,0..1000] of longint;
  f:array[1..1000,1..1000] of char;
  r,s,k,i,j,x,y,m,n:longint;
begin
  readln(r,s,k);
  for i:=1 to r do
  begin
    for j:=1 to s do
    begin
      read(f[i,j]);
      t[i,j]:=t[i-1,j]+t[i,j-1]-t[i-1,j-1];
      if f[i,j]='*' then inc(t[i,j]);
    end;
    readln;
  end;
  for i:=1 to r-k+1 do
    for j:=1 to s-k+1 do
    begin
      n:=t[i+k-2,j+k-2]-t[i,j+k-2]-t[i+k-2,j]+t[i,j];
      if n>m then
      begin
        m:=n; x:=i; y:=j;
      end;
    end;
  for i:=1 to k-2 do
  begin
    f[x+i,y]:='|'; f[x+i,y+k-1]:='|'; f[x,y+i]:='-'; f[x+k-1,y+i]:='-';
  end;
  f[x,y]:='+'; f[x,y+k-1]:='+'; f[x+k-1,y]:='+'; f[x+k-1,y+k-1]:='+';
  writeln(m);
  for i:=1 to r do
  begin
    for j:=1 to s do write(f[i,j]);
    writeln;
  end;
end.