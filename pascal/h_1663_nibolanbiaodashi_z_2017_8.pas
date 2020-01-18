program h_1663_nibolanbiaodashi_zhai_2017_8_10;
var
  s:array[1..10000] of real;
  i,top,t2:longint;
  b,b1:boolean;
  e:string;
  t:real;
procedure put(n:real);
begin
  dec(top);
  s[top]:=n;
end;
begin
  readln(e);
  t:=0; t2:=1;
  for i:=length(e) downto 1 do
    if (e[i]>='0')and(e[i]<='9')
    then begin
           if b1
           then begin
                  t:=t+(ord(e[i])-ord('0'))*t2;
                  t2:=t2*10;
                end
           else t:=(t+ord(e[i])-ord('0'))/10;
           b:=true;
         end
    else begin
           if e[i]='.' then
           begin
             b1:=true;
             continue;
           end;
           if b then
           begin
             inc(top);
             s[top]:=t;
             //writeln(t:0:3);
             b:=false; b1:=false; t:=0; t2:=1;
           end;
           if e[i]='+' then put(s[top]+s[top-1]);
           if e[i]='-' then put(s[top]-s[top-1]);
           if e[i]='*' then put(s[top]*s[top-1]);
           if e[i]='/' then put(s[top]/s[top-1]);
         end;
  writeln(s[1]:0:6);
end.
