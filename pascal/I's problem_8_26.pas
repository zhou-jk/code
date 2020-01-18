//Tyvj 4752
var
  a,b,s,ans:longint;
begin
  read(a,b);
  s:=b-a+1;
  ans:=trunc(sqrt(s*2));
  if (ans+1)*ans div 2<s then inc(ans);
  write(ans);
end.