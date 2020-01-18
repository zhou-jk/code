var
  v:array[1..100] of boolean;
  a,b,c,d,i,ans:longint;
begin
  //assign(input,'paint.in'); assign(output,'paint.out');
  //reset(input); rewrite(output);
  read(a,b,c,d);
  ans:=b-a;
  for i:=a+1 to b do v[i]:=true;
  for i:=c+1 to d do
    if not v[i] then inc(ans);
  write(ans);
  //close(input); close(output);
end.