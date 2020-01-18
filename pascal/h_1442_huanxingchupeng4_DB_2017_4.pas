program h_1442_huanxingchupeng4_DB_2017_4_8;
var
  f:array[0..100,1..7] of int64;
  r,r1:array[1..200] of longint;
  sum,cost,ans:int64;
  n,k,i,j,p,q:byte;
function min(a,b:int64):int64;
begin
  if a<b then exit(a);
  min:=b;
end;
begin
  readln(n,k);
  for i:=1 to n do
  begin
    readln(r[i]);
    r[i+n]:=r[i];
  end;
  ans:=maxlongint;
  for i:=1 to n do
  begin
    for j:=1 to n do r1[j]:=r[i+j-1];
    fillchar(f,sizeof(f),127);
    f[0,1]:=0;
    for j:=1 to n do
    begin
      f[j,1]:=f[j-1,1]+r1[j]*(j-1);
      //writeln(j,' ',f[j,1]);
    end;
    for j:=2 to k do
      for p:=j to n do
      begin
        sum:=0; cost:=0;
        for q:=p downto j do
        begin
          f[p,j]:=min(f[p,j],f[q-1,j-1]+cost);
          inc(sum,r1[q]); inc(cost,sum);
          //writeln(i,' ',j,' ',p,' ',q,'#',f[p,j],' ',sum,' ',cost);
        end;
      end;
    ans:=min(ans,f[n,k]);
  end;
  writeln(ans);
end.

