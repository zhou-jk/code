program h_1662_bolanbiaodashi_stack_2017_8_10;
var
  p:array['('..'/'] of byte;
  s:array[1..50] of char;
  i,j,t:byte;
  exp:string;
  c:char;
begin
  readln(exp);
  exp:=exp+')';
  p['(']:=0; p[')']:=0; p['+']:=1; p['-']:=1; p['*']:=2; p['/']:=2;
  t:=1; s[1]:='(';
  //write('( ');
  for i:=1 to length(exp) do
  begin
    c:=exp[i];
    {for j:=1 to t do write(s[j]);
    writeln;}
    if (c>='A')and(c<='Z')
    then write(c)
    else if (c='(')or(p[c]>p[s[t]])
         then begin
                inc(t);
                s[t]:=c;
              end
         else begin
                while p[s[t]]>=p[c] do
                begin
                  if s[t]='(' then break;
                  write(s[t]);
                  dec(t);
                end;
                if c=')'
                then dec(t)
                else begin
                      inc(t);
                      s[t]:=c;
                     end;
              end;
    //write(c,' ');
  end;
end.

