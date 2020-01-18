program h_1708_hebingguozi_duilie_2017_7_24;
var
  n,a,i,j,t,t1,t2,t3,max,ans:longint;
  s,s1:array[1..50000] of longint;
  num:array[1..20000] of integer;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(a);
    inc(num[a]);
    if a>max then max:=a;
  end;
  for i:=1 to max do
    while num[i]>0 do
    begin
      inc(t);
      s[t]:=i;
      dec(num[i]);
    end;
  i:=1; j:=1; t:=0;
  while (i<=n)and(j<=t)or(i<n)or(j<t) do
  begin
    //writeln(i,' ',j,' ',t);
    if (j<=t)and(i<=n)
    then t1:=s[i]+s1[j]
    else t1:=maxlongint;
    if i<n
    then t2:=s[i]+s[i+1]
    else t2:=maxlongint;
    if j<t
    then t3:=s1[j]+s1[j+1]
    else t3:=maxlongint;
    //writeln(t1,' ',t2,' ',t3);
    inc(t);
    if (t1<t2)and(t1<t3)
    then begin
           ans:=ans+t1;
           s1[t]:=t1;
           inc(i); inc(j);
         end
    else if t2<t3
         then begin
                ans:=ans+t2;
                s1[t]:=t2;
                i:=i+2;
              end
         else begin
                ans:=ans+t3;
                s1[t]:=t3;
                j:=j+2;
              end;
  end;
  writeln(ans);
end.

