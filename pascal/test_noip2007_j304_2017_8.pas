program test_noip2007_j304_2017_8_6;
type
  str1=string[100];
  str2=string[200];
var
  s1:str1;
  s2:str2;
function isalpha(c:char):boolean;
var i:integer;
begin
  i:=ord(c);
  if ((i>=65)and(i<=90))or((i>=97)and(i<=122))
  then isalpha:=true
  else isalpha:=false;
end;
function isdight(c:char):boolean;
var i:integer;
begin
  i:=ord(c);
  if (i>=48)and(i<=57)
  then isdight:=true
  else isdight:=false;
end;
procedure expand(s1:str1;var s2:str2);
var
  i,j:integer;
  a,b,c:char;
begin
  j:=1; c:=char(1); i:=0;
  while (i<=ord(s1[0])) do //if there is "<",the answer will be "s2[0]:=j-1;".
  begin
    inc(i); c:=s1[i];
    if c='-'
    then begin
           a:=s1[i-1]; b:=s1[i+1];
           if (isalpha(a)and isalpha(b))or(isdight(a)and isdight(b))
           then begin
                  dec(j);
                  while (ord(upcase(a))<ord(upcase(s1[i+1]))) do
                  begin
                    s2[j]:=a;
                    inc(j); inc(a);
                  end;
                end
           else begin
                  s2[j]:=c;
                  inc(j);
                end;
         end
    else begin
           s2[j]:=c;
           inc(j);
         end;
    writeln(j);
  end;
  s2[0]:=char(j-2);
end;
begin
  readln(s1);
  expand(s1,s2);
  writeln(s2,' ',ord(s2[0]),' ',length(s2));
end.
