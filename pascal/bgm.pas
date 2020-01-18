var
  s:array['B'..'S',0..500] of int64;
  n,i,j,k,p:longint;
  a:int64;
  c:char;
begin
  assign(input,'bgm.in'); assign(output,'bgm.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(c);
    inc(s[c,0]);
    readln(s[c,s[c,0]]);
  end;
  for i:=1 to s['B',0] do
    for j:=1 to s['E',0] do
      for k:=1 to s['S',0] do
        for p:=1 to s['I',0] do
          if (s['B',i]+2*s['E',j]+2*s['S',k]+s['I',p])mod 7=0 then inc(a,s['G',0]*s['O',0]*s['M',0]);
  for i:=1 to s['G',0] do
    for j:=1 to s['O',0] do
      for k:=1 to s['E',0] do
        for p:=1 to s['S',0] do
          if (s['G',i]+s['O',j]+s['E',k]+s['S',p])mod 7=0 then inc(a,s['B',0]*s['I',0]*s['M',0]);
  for i:=1 to s['M',0] do
    for j:=1 to s['O',0] do
      if (s['M',0]+2*s['O',0])mod 7=0 then inc(a,s['B',0]*s['E',0]*s['S',0]*s['I',0]*s['G',0]);
  write(a);
  close(input); close(output);
end.