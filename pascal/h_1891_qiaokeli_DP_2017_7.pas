program h_1891_qiaokeli_DP_2017_7_10;
var
  f:array[0..30,0..30,0..50] of longint;
  t,n,m,k,i,j,p,q:integer;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  min:=b;
end;
begin
  readln(t);
  writeln(sizeof(f));
  fillchar(f,sizeof(f),63);
  for i:=0 to 30 do
    for j:=0 to 30 do
    begin
      f[i,j,0]:=0;
      if i*j<=50 then f[i,j,i*j]:=0;
    end;
  writeln(f[28,23,50]);
  for i:=1 to 30 do
    for j:=1 to 30 do
      for k:=1 to 50 do
        for p:=0 to k do
        begin
          if (i=28)and(j=23)and(k=50) then writeln(p,' ',f[i,j,k]);
          //writeln(i,' ',j,' ',k,' ',p);
          for q:=1 to i div 2 do
          begin
            f[i,j,k]:=min(f[i,j,k],min(f[q,j,p],f[j,q,p])+min(f[i-q,j,k-p],f[j,i-q,k-p])+j*j);
            if (i=28)and(j=23)and(k=50) then writeln(f[i,j,k],' ',f[q,j,p],' ',f[j,q,p],' ',f[i-q,j,k-p],' ',f[j,i-q,k-p]);
          end;
          if (i=28)and(j=23)and(k=50) then writeln;
          for q:=1 to j div 2 do
          begin
            f[i,j,k]:=min(f[i,j,k],min(f[i,q,p],f[q,i,p])+min(f[i,j-q,k-p],f[j-q,i,k-p])+i*i);
            if (i=28)and(j=23)and(k=50) then writeln(f[i,j,k],' ',f[i,j,k],' ',f[i,q,p],' ',f[q,i,p],' ',f[i,j-q,k-p],' ',f[j-q,i,k-p]);
          end;
        end;
  for i:=1 to t do
  begin
    readln(n,m,k);
    writeln(f[n,m,k]);
  end;
end.

