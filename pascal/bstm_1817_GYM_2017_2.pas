program bstm_1817_GYM_2017_2_4;
var
  l,m,n,gcd,ans,min,i,lcm:qword;
function g(p,q:qword):qword;
begin
  if p mod q=0 then exit(q);
  g:=g(q,p mod q);
end;
begin
  readln(l,m,n);
  if m<n
  then min:=m
  else min:=n;
  gcd:=g(m,n); lcm:=m*(n div gcd);
  if l>=min-1
  then ans:=min-1
  else ans:=l;
  i:=l div lcm;
  if i>0 then
  begin
    inc(ans,min*(i-1));
    if l-i*lcm<min-1
    then inc(ans,l-i*lcm+1)
    else inc(ans,min);
  end;
  gcd:=g(l,ans);
  writeln(ans div gcd,'/',l div gcd);
end.


