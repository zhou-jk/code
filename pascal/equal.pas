var
  n:array[1..2]of longint;
  s,n1:string;
  i,j:byte;
  c,cc:char;
begin
  assign(input,'equal.in'); assign(output,'equal.out');
  reset(input); rewrite(output);
  readln(s);
  s:=s+' ';
  for i:=1 to length(s) do
    if (s[i]>='0')and(s[i]<='9')
    then n1:=n1+s[i]
    else if s[i]='?'
         then if j=2
              then begin
                     if c='-'
                     then writeln(-(n[1]+n[2]))
                     else writeln(n[1]+n[2]);
                     exit;
                   end
              else cc:=c
         else begin
                if (s[i-1]>='0')and(s[i-1]<='9') then
                begin
                  inc(j);
                  val(n1,n[j]);
                  if c='-' then n[j]:=-n[j];
                  n1:='';
                end;
                c:=s[i];
              end;
  if cc='-'
  then writeln(n[1]-n[2])
  else writeln(-(n[1]-n[2]));
  close(input); close(output);
end.


