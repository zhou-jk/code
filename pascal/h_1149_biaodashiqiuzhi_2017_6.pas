program h_1149_biaodashiqiuzhi_2017_6_14;
var
  s1:array[1..100001] of longint;
  s2:array[1..100000] of char;
  i,t1,t2:longint;
  s:ansistring;
  n:string;
begin
  readln(s);
  s:=s+'+';
  for i:=1 to length(s) do
    if (s[i]>='0')and(s[i]<='9')
    then n:=n+s[i]
    else begin
           inc(t1);
           delete(n,1,length(n)-4);
           val(n,s1[t1]);
           if (s[i]='*')and((t2=0)or(s2[t2]='+'))
           then begin
                  inc(t2);
                  s2[t2]:=s[i];
                end
           else begin
                  while (t2>0)and((s2[t2]='*')or(s[i]='+')) do
                  begin
                    dec(t1);
                    if s2[t2]='*'
                    then s1[t1]:=s1[t1]*s1[t1+1]
                    else s1[t1]:=s1[t1]+s1[t1+1];
                    str(s1[t1],n);
                    delete(n,1,length(n)-4);
                    val(n,s1[t1]);
                    dec(t2);
                  end;
                  inc(t2);
                  s2[t2]:=s[i];
                end;
           n:='';
         end;
  writeln(s1[1]);
end.
