type arr=array[1..10] of longint;
var
  a,b,c:arr;
  i,j,e1,e2,f:longint;
procedure px(s,m:longint;var n:arr);
  var
    d:array[0..100] of longint;
    e:longint;
  begin
    for i:=0 to 100 do
      d[i]:=0;
    for i:=s to m do
      inc(d[n[i]]);
    for i:=0 to 100 do
      begin
        while d[i]>0 do
          begin
            n[s]:=i;
            d[i]:=d[i]-1;
            inc(s);
            if s>m then break;
          end;
        if s>m then break;
      end;
  end;
begin
  for i:=1 to 10 do
     begin
       if i=10 then
         readln(f)
       else
         read(f);
       if f mod 2=0 then
         begin
           inc(e1);
           c[e1]:=f;
         end
       else
         begin
           inc(e2);
           b[e2]:=f;
         end;
     end;
  px(1,e2,b);
  for i:=e2 downto 1 do
    begin
      inc(j);
      a[j]:=b[i];
    end;
  px(1,e1,c);
  for i:=1 to e1 do
    begin
      a[e2+i]:=c[i];
    end;
  for i:=1 to 10 do
    write(a[i],' ');
  writeln;
  readln;
end.


