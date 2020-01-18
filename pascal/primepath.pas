type n=array[1..4] of integer;
var
  f,ce:array[1..1500] of integer;
  p:array[1..10000] of boolean;
  a,b,i,j,h,t,f2:integer;
  f1:n;
function zh(num:integer):n;
var i:integer;
begin
  for i:=4 downto 1 do
  begin
    zh[i]:=num mod 10;
    num:=num div 10;
  end;
end;
begin
  assign(input,'primepath.in'); assign(output,'primepath.out');
  reset(input); rewrite(output);
  readln(a,b);
  for i:=2 to 100 do
    if not p[i] then
      for j:=1000 div i to 10000 div i do
        if not p[j] then p[i*j]:=true;
  for i:=1 to 999 do p[i]:=true;
  t:=1; f[1]:=a; p[a]:=true;
  while h<t do
  begin
    inc(h);
    for i:=1 to 4 do
    begin
      f1:=zh(f[h]);
      for j:=0 to 9 do
      begin
        //writeln('#',h,' ',t,' ',i,' ',j);
        f1[i]:=j;
        f2:=f1[1]*1000+f1[2]*100+f1[3]*10+f1[4];
        if f2=b then
        begin
          writeln(ce[h]+1);
          exit;
        end;
        if not p[f2] then
        begin
          inc(t);
          f[t]:=f2; p[f2]:=true; ce[t]:=ce[h]+1;
        end;
      end;
    end;
  end;
  writeln(0);
  close(input); close(output);
end.
