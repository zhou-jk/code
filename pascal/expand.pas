var
  c:array[1..3,'0'..'z'] of char;
  s,t:string;
  p1,p2,p3,l,i,k:longint;
  j:char;
function id(c:char):boolean;
begin
  exit((c>='0')and(c<='9'));
end;
function ic(c:char):boolean;
begin
  exit((c>='a')and(c<='z'));
end;
begin
  assign(input,'expand.in'); assign(output,'expand.out');
  reset(input); rewrite(output);
  readln(p1,p2,p3);
  readln(s);
  for j:='0' to '9' do
  begin
    c[1,j]:=j; c[2,j]:=j; c[3,j]:='*';
  end;
  for j:='a' to 'z' do
  begin
    c[1,j]:=j; c[2,j]:=upcase(j); c[3,j]:='*';
  end;
  l:=length(s);
  for i:=1 to l do
    if (s[i]='-')and(i>1)and(i<l)
    then if (id(s[i-1])and id(s[i+1])or ic(s[i-1])and ic(s[i+1]))and(s[i-1]<s[i+1])
         then begin
                t:='';
                for j:=succ(s[i-1]) to pred(s[i+1]) do
                  for k:=1 to p2 do t:=t+c[p1,j];
                if p3=2
                then for k:=length(t) downto 1 do write(t[k])
                else write(t);
              end
         else write('-')
    else write(s[i]);
  close(input); close(output);
end.