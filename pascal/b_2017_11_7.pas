var
  t,m,h1,h2,a1,a2,x1,x2,y1,y2,i,t1,t2:longint;
  v:array[0..999999] of boolean;
function solve(w,x,y,m,a:longint):longint;
begin
  fillchar(v,1000000,0);
  //writeln('*');
  solve:=0;
  while w<>a do
  begin
    //writeln(solve);
    if v[w] then exit(-1);
    v[w]:=true; w:=(x*w+y)mod m;
    inc(solve);
  end;
end;
function gcd(a,b:longint):longint;
begin
  if a mod b=0
  then exit(b)
  else exit(gcd(b,a mod b));
end;
begin
  assign(input,'b.in'); assign(output,'b.out');
  reset(input); rewrite(output);
  read(t);
  for i:=1 to t do
  begin
    read(m,h1,a1,x1,y1,h2,a2,x2,y2);
    //writeln('*');
    t1:=solve(h1,x1,y1,m,a1); t2:=solve(h2,x2,y2,m,a2);
    if (t1=-1)or(t2=-1) then
    begin
      writeln(-1);
      continue;
    end;
    writeln(t1*t2 div gcd(t1,t2));
  end;
  close(input); close(output);
end.
