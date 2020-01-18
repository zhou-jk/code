var
  k,k1,a,b,p,p1,p2,ans:longint;
  s:string;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  max:=b;
end;
begin
  assign(input,'equal.in'); assign(output,'equal.out');
  reset(input); rewrite(output);
  readln(s);
  k:=pos('?',s); k1:=pos('=',s); p1:=pos('+',s); p2:=pos('-',s); p:=max(p1,p2);
  if k>k1
  then begin
         val(copy(s,1,p-1),a); val(copy(s,p+1,k1-1-p),b);
         if p1>0
         then ans:=a+b
         else ans:=a-b;
       end
  else begin
         val(copy(s,k1+1,length(s)-k1+1),b);
         if k=1
         then val(copy(s,p+1,k1-1-p),a)
         else val(copy(s,1,p-1),a);
         if p1>0
         then ans:=b-a
         else if k=1
              then ans:=a+b
              else ans:=a-b;
       end;
  writeln(ans);
  close(input); close(output);
end.


