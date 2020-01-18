program h_1180_juzhenqushuyouxiwugaojingduban_DP_2017_8_4; //different from 2017.4
var
  f:array[0..80,0..80] of qword;
  a,s:array[1..80] of qword;
  n,m,i,j,k:byte;
  t,ans:qword;
function max(a,b:qword):qword;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  readln(n,m);
  s[1]:=2;
  for i:=2 to m do s[i]:=s[i-1]*2;
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[j]);
    for j:=1 to m do
    begin
      //writeln(f[j-1,0]);
      f[j,0]:=f[j-1,0]+a[m-j+1]*s[j];
      //writeln('% ',i,' ',j,' ',f[j,0],' ',a[m-j+1],' ',s[j]);
      for k:=1 to j-1 do f[j,k]:=max(f[j-1,k]+a[m-(j-k)+1]*s[j],f[j-1,k-1]+a[k]*s[j]);
        //writeln('* ',i,' ',j,' ',k,' ',f[j,k]);
      f[j,j]:=f[j-1,j-1]+a[j]*s[j];
      //writeln('& ',i,' ',j,' ',f[j,0]);
    end;
    t:=f[m,0];
    for j:=1 to m do t:=max(t,f[m,j]);
    inc(ans,t);
  end;
  writeln(ans);
end.



