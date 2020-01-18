program h_1662_bolanbiaodashi_2017_6_14;
var
  rank:array['('..'/'] of integer; //40..47
  stack:array[1..50] of char;
  i,top:byte;
  s:string;
procedure push;
begin
  inc(top);
  stack[top]:=s[i];
end;
begin
  {rank['(']:=0;} rank['+']:=1; rank['-']:=1; rank['*']:=2; rank['/']:=2;
  top:=1; stack[1]:='(';
  readln(s);
  s:=s+')';
  for i:=1 to length(s) do
    if {(}s[i]>='A'{)and(s[i]<='Z')}
    then write(s[i])
    else if (rank[s[i]]>rank[stack[top]])or(s[i]='(')
         then push
         else begin
                while rank[stack[top]]>rank[s[i]] do
                begin
                  write(stack[top]);
                  dec(top);
                end;
                if s[i]=')'
                then dec(top)
                else push;
              end;
end.