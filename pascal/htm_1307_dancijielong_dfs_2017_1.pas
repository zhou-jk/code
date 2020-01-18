program htm_1307_dancijielong_dfs_2017_1_28;
var
  s:array[1..20] of string;
  c:array[1..20] of integer;
  f:array[1..20,1..20] of integer;
  n,i,j,k,ans:longint;
  a,e:string;
  g:char;
function min(a,b:integer):integer;
begin
  if a<b then exit(a);
  exit(b);
end;
procedure dfs(k,len:integer);
var
  i:integer;
begin
  if len>ans then ans:=len;
  for i:=1 to n do
    if (c[i]<2)and(f[k,i]>0) then
    begin
        inc(c[i]);
        dfs(i,len+length(s[i])-f[k,i]);
        dec(c[i]);
    end;
end;
begin
  readln(n);
  for i:=1 to n do readln(s[i]);
  readln(g);
  for i:=1 to n do
    for j:=1 to n do
    begin
      a:=''; e:='';
      for k:=0 to min(length(s[i]),length(s[j]))-2 do
      begin
        a:=s[i][length(s[i])-k]+a; e:=e+s[j][1+k];
        if a=e then begin f[i,j]:=k+1; break; end;
      end;
    end;
  for i:=1 to n do if s[i][1]=g then begin inc(c[i]); dfs(i,length(s[i])); dec(c[i]); end;
  writeln(ans);
end.
