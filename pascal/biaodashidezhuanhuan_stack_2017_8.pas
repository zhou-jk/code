//PrayerOJ 1661
var
  rank:array['#'..'^'] of longint;
  stack1:array[1..128] of longint;
  stack:array[1..128] of char;
  i,j,top,l,t:longint;
  s,s1:string;
procedure push;
begin
  inc(top);
  stack[top]:=s[i];
end;
begin
  rank[')']:=1; rank['+']:=1; rank['-']:=1; rank['*']:=2; rank['/']:=2; rank['^']:=3;
  top:=1; stack[1]:='(';
  readln(s);
  s:=s+')';
  for i:=1 to length(s) do
    if (s[i]>='0')and(s[i]<='9')
    then s1:=s1+s[i]
    else if (rank[s[i]]>rank[stack[top]])or(s[i]='(')
         then push
         else begin
                while rank[stack[top]]>=rank[s[i]] do
                begin
                  s1:=s1+stack[top];
                  dec(top);
                end;
                if s[i]=')'
                then dec(top)
                else push;
              end;
  l:=length(s1);
  for i:=1 to l do write(s1[i],' ');
  writeln;
  for i:=1 to l do
    if (s1[i]>='0')and(s1[i]<='9')
    then begin
           inc(top);
           stack1[top]:=ord(s1[i])-ord('0');
         end
    else begin
           dec(top);
           case s1[i] of
             '+':stack1[top]:=stack1[top]+stack1[top+1];
             '-':stack1[top]:=stack1[top]-stack1[top+1];
             '*':stack1[top]:=stack1[top]*stack1[top+1];
             '/':stack1[top]:=stack1[top]div stack1[top+1];
             '^':begin
                   t:=1;
                   for j:=1 to stack1[top+1] do t:=t*stack1[top];
                   stack1[top]:=t;
                 end;
           end;
           for j:=1 to top do write(stack1[j],' ');
           for j:=i+1 to l do write(s1[j],' ');
           writeln;
         end;
end.