program h_1099_baozhuang_tanxin_2017_8_18;
var
  n:array[1..6] of longint;
  a,i,t:longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  for i:=1 to 6 do read(n[i]);
  a:=n[6];
  inc(a,n[5]);
  dec(n[1],min(n[5]*11,n[1]));
  inc(a,n[4]);
  t:=min(n[4]*5,n[2]);
  dec(n[2],t);
  dec(n[1],min(n[4]*20-t*4,n[1]));
  inc(a,(n[3]+3)div 4);
  case n[3]mod 4 of
    1:begin
        t:=min(5,n[2]);
        dec(n[2],t);
        dec(n[1],min(27-t*4,n[1]));
      end;
    2:begin
        t:=min(3,n[2]);
        dec(n[2],t);
        dec(n[1],min(18-t*4,n[1]));
      end;
    3:begin
        t:=min(1,n[2]);
        dec(n[2],t);
        dec(n[1],min(9-t*4,n[1]));
      end;
  end;
  inc(a,(n[2]+8)div 9);
  if n[2]mod 9=0
  then t:=0
  else t:=min(n[1],36-n[2]mod 9*4);
  dec(n[1],t);
  inc(a,(n[1]+35)div 36);
  write(a);
end.