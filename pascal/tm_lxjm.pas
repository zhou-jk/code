var
  a:array[1..20,1..20] of string;
  g:array[1..400] of string;
  m:array['A'..'Z'] of longint;
  row,col,i,j,t,f,b,h,k:longint;
  d,l:string;
  e:char;
  c:boolean;
begin
  readln(row,col,e,d);
  for e:='A' to 'Z' do
    begin
      inc(i);
      m[e]:=i;
    end;
  for i:=1 to length(d) do
    begin
      h:=m[d[i]];
      j:=1;
      while h>0 do
        begin
          k:=h mod 2;
          h:=h div 2;
          str(k,l);
          g[i]:=l+g[i];
        end;
      while length(g[i])<5 do
        g[i]:='0'+g[i];
      writeln(g[i]);
    end;
  t:=row;
  f:=col;
  i:=1;
  j:=1;
  while (t>0) and (f>0) do
    begin
      c:=false;
      inc(b);
      while (b mod 4=1) and (j<=f+(col-f) div 2) do
        begin
          writeln(a[i,j]);
          inc(j);
          c:=true;
        end;
      if c then
        begin
          inc(i);
          t:=t-1;
          j:=j-1;
          continue;
        end;
      while (b mod 4=2) and (i<=t+(row-t) div 2+1) do
        begin
          writeln(a[i,j]);
          inc(i);
          c:=true;
        end;
      if c then
        begin
          j:=j-1;
          f:=f-1;
          i:=i-1;
          continue;
        end;
      while (b mod 4=3) and (j>(col-f) div 2) do
        begin
          writeln(a[i,j]);
          j:=j-1;
          c:=true;
        end;
      if c then
        begin
          i:=i-1;
          t:=t-1;
          j:=j+1;
          continue;
        end;
      while (b mod 4=0) and (i>(row-t) div 2) do
        begin
          writeln(a[i,j]);
          i:=i-1;
          c:=true;
        end;
      if c then
        begin
          inc(i);
          f:=f-1;
          j:=j+1;
          continue;
        end;
    end;
  readln;
end.

