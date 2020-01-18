uses math;
var
  n,i,j,k,f,t,t1,minx,miny,maxx,maxy:longint;
  x,y:array[1..4] of longint;
  s:string;
begin
  assign(input,'ballet.in'); assign(output,'ballet.out');
  reset(input); rewrite(output);
  x[1]:=1; y[1]:=1; x[2]:=1; y[2]:=2; x[3]:=2; y[3]:=1; x[4]:=2; y[4]:=2;
  minx:=1; miny:=1; maxx:=2; maxy:=2;
  readln(n);
  for i:=1 to n do
  begin
    readln(s);
    case s[1]+s[2] of
      'FL':t:=1;
      'FR':t:=2;
      'RL':t:=3;
      'RR':t:=4;
    end;
    if (f=0)and(s[3]='F')or(f=1)and(s[3]='L')or(f=2)and(s[3]='B')or(f=3)and(s[3]='R') then dec(x[t]);
    if (f=0)and(s[3]='B')or(f=1)and(s[3]='R')or(f=2)and(s[3]='F')or(f=3)and(s[3]='L') then inc(x[t]);
    if (f=0)and(s[3]='L')or(f=1)and(s[3]='B')or(f=2)and(s[3]='R')or(f=3)and(s[3]='F') then dec(y[t]);
    if (f=0)and(s[3]='R')or(f=1)and(s[3]='F')or(f=2)and(s[3]='L')or(f=3)and(s[3]='B') then inc(y[t]);
    if s[3]='P' then
    begin
      inc(f);
      f:=f mod 4;
      for j:=1 to 4 do
      begin
        t1:=x[j];
        x[j]:=x[t]-(y[t]-y[j]);
        y[j]:=y[t]-(t1-x[t]);
      end;
    end;
    //writeln(i);
    //for j:=1 to 4 do writeln(x[j],' ',y[j]);
    for j:=1 to 4 do
    begin
      for k:=j+1 to 4 do
        if (x[j]=x[k])and(y[j]=y[k]) then
        begin
          writeln(-1);
          exit;
        end;
      minx:=min(minx,x[j]);
      miny:=min(miny,y[j]);
      maxx:=max(maxx,x[j]);
      maxy:=max(maxy,y[j]);
    end;
  end;
  writeln((maxx-minx+1)*(maxy-miny+1));
  close(input); close(output);
end.