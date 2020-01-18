program codevs_1029bianliwenti_shu_2016_12_23;
var
  t:array[1..26] of record
                    c:char;
                    l,r:integer;
                    end;
  s:array['a'..'z'] of boolean;
  a,b,a1,b1:string[26];
  i,n:integer;
  ans:longint;
procedure q(k:integer);
begin
  if t[k].c<>' ' then a1:=a1+t[k].c;
  if t[k].l>0 then q(t[k].l);
  if t[k].r>0 then q(t[k].r);
end;
procedure h(k:integer);
begin
  if t[k].l>0 then h(t[k].l);
  if t[k].r>0 then h(t[k].r);
  if t[k].c<>' ' then b1:=b1+t[k].c;
end;
procedure dfs(k,z:integer);
var i:char;
begin
  if z=n then
  begin
    q(1);
    h(1);
    if (a1=a)and(b1=b) then inc(ans);
    a1:=''; b1:='';
    exit;
  end;
  if k*2<=n then t[k].l:=k*2;
  if k*2+1<=n then t[k].r:=k*2+1;
  for i:='a' to 'z' do
    if s[i] then
    begin
      s[i]:=false;
      t[k].c:=i;
      if t[k].l>0 then dfs(t[k].l,z+1);
      if t[k].r>0 then dfs(t[k].r,z+1);
      t[k].c:=' ';
      s[i]:=true;
    end;
end;
begin
  readln(a);
  readln(b);
  n:=length(a);
  for i:=1 to n do s[a[i]]:=true;
  dfs(1,0);
  writeln(ans);
end.


