program h_1060_bingdu_TopSort_2017_5_28;
var
  g:array['a'..'z','a'..'z'] of boolean;
  ind,n:array['a'..'z'] of byte;
  b:array['a'..'z'] of boolean;
  s:array[1..50000] of string;
  stack:array[1..26] of char;
  a:array['a'..'z'] of char;
  k,i,j,q,top,num,m:word;
  p,v,c:char;
procedure error;
begin
  writeln(0);
  halt;
end;
begin
  readln(k);
  for i:=1 to k do
  begin
    readln(s[i]);
    for j:=1 to i-1 do
    begin
      q:=1;
      while (s[j,q]=s[i,q])and(q<length(s[j]))and(q<length(s[i])) do inc(q);
      if s[j,q]<>s[i,q] then g[s[j,q],s[i,q]]:=true;
    end;
    for j:=1 to length(s[i]) do b[s[i,j]]:=true;
  end;
  readln(s[1]);
  c:='a';
  for p:='a' to 'z' do
    if b[p] then
    begin
      inc(num);
      //write(p,' ');
      for v:='a' to 'z' do
        if g[v,p] then
        begin
          //write(v,' ');
          inc(ind[p]);
        end;
      //writeln;
      if ind[p]=0 then
      begin
        inc(top);
        stack[top]:=p; a[p]:=c;
        c:=succ(c);
      end;
      //writeln('#',p,' ',ind[p]);
    end;
  //writeln(top);
  if top>1 then error;
  for i:=1 to num do
  begin
    //writeln(i,' ',top,' ',stack[top]);
    if top=0 then error;
    m:=0;
    p:=stack[top];
    dec(top);
    for v:='a' to 'z' do
      if g[p,v] then
      begin
        dec(ind[v]);
        if ind[v]=0 then
        begin
          inc(top);
          stack[top]:=v; a[v]:=c;
          c:=succ(c);
          inc(m);
          if m>1 then error;
        end;
      end;
  end;
  for i:=1 to length(s[1]) do
    if ord(a[s[1,i]])=0 then error;
  for i:=1 to length(s[1]) do write(a[s[1,i]]);
  {for p:='a' to 'z' do writeln(p,' ',a[p]);
  readln(k);
  for i:=1 to k do
  begin
    readln(s);
    write('# ');
    for j:=1 to length(s) do write(a[s[j]]);
    writeln;
  end;}
end.


