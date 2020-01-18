program bstm_1813_jiecheng2_2017_2_4;
var
  n,k,i,i1:longint;
  ans:string;
  s,k1:int64;
begin
  readln(n,k);
  s:=1; k1:=1;
  for i:=1 to k+2 do k1:=k1*10;
  for i:=2 to n do
  begin
    i1:=i;
    while i1 mod 10=0 do i1:=i1 div 10;
    s:=s*i1;
    while s mod 10=0 do s:=s div 10;
    s:=s mod k1;
    //writeln('#',i,' ',s);
  end;
  str(s,ans);
  if length(ans)<k
  then begin
         for i:=1 to k-length(ans) do write(0);
         writeln(ans);
       end
  else for i:=length(ans)-k+1 to length(ans) do write(ans[i]);
end.
