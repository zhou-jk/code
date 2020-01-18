var
  d:array[1..3,1..3] of integer;
  i,j,k,l,m:integer;
  ans:longint;
  s,n:string;
  b:boolean;
function p:boolean;
begin
  p:=true;
  if d[3,1] div 1000<>d[3,3] mod 10 then exit(false);
  if d[3,1] div 100 mod 10<>d[3,3] div 10 then exit(false);
  if d[3,1] div 10 mod 100 mod 10<>d[3,2] mod 10 then exit(false);
  if d[3,1] mod 1000 mod 100 mod 10<>d[3,2] div 10 then exit(false);
  //writeln('#',d[3,1],d[3,2],d[3,3]);
end;
begin
  assign(input,'date.in');
  assign(output,'date.out');
  reset(input);
  rewrite(output);
  for i:=1 to 2 do
  begin
    readln(s);
    n:='';
    for j:=1 to 4 do n:=n+s[j];
    val(n,d[i,1]);
    n:=s[5]+s[6];
    val(n,d[i,2]);
    n:=s[7]+s[8];
    val(n,d[i,3]);
  end;
  if d[1,1]=d[2,1] then
  begin
    d[3,1]:=d[1,1];
    if (d[1,1] mod 4=0)and(d[1,1] mod 100<>0)or(d[1,1] mod 400=0) then b:=true;
    for j:=d[1,2] to d[2,2] do
    begin
      d[3,2]:=j;
      if (j=1)or(j=3)or(j=5)or(j=7)or(j=8)or(j=10)or(j=12)
      then l:=31
      else if (j=4)or(j=6)or(j=9)or(j=11)
           then l:=30
           else if b
              then l:=29
              else l:=28;
      for k:=1 to l do
      begin
        d[3,3]:=k;
        if p then inc(ans);
      end;
    end;
    writeln(ans);
    exit;
  end;
  d[3,1]:=d[1,1];
  if (d[1,1] mod 4=0)and(d[1,1] mod 100<>0)or(d[1,1] mod 400=0) then b:=true;
  for j:=d[1,2] to 12 do
  begin
    d[3,2]:=j;
    if (j=1)or(j=3)or(j=5)or(j=7)or(j=8)or(j=10)or(j=12)
    then l:=31
    else if (j=4)or(j=6)or(j=9)or(j=11)
         then l:=30
         else if b
              then l:=29
              else l:=28;
    for k:=1 to l do
    begin
      d[3,3]:=k;
      if p then inc(ans);
    end;
  end;
  for i:=d[1,1]+1 to d[2,1]-1 do
  begin
    d[3,1]:=i;
    b:=false;
    if (i mod 4=0)and(i mod 100<>0)or(i mod 400=0) then b:=true;
    for j:=1 to 12 do
    begin
      d[3,2]:=j;
      if (j=1)or(j=3)or(j=5)or(j=7)or(j=8)or(j=10)or(j=12)
      then l:=31
      else if (j=4)or(j=6)or(j=9)or(j=11)
           then l:=30
           else if b
                then l:=29
                else l:=28;
      for k:=1 to l do
      begin
        d[3,3]:=k;
        if p then inc(ans);
      end;
    end;
  end;
  d[3,1]:=d[2,1];
  b:=false;
  if (i mod 4=0)and(i mod 100<>0)or(i mod 400=0) then b:=true;
  for j:=1 to d[2,2] do
  begin
    d[3,2]:=j;
    if (j=1)or(j=3)or(j=5)or(j=7)or(j=8)or(j=10)or(j=12)
    then l:=31
    else if (j=4)or(j=6)or(j=9)or(j=11)
         then l:=30
         else if b
              then l:=29
              else l:=28;
    for k:=1 to l do
    begin
      d[3,3]:=k;
      if p then inc(ans);
    end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.






