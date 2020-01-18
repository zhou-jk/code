type
  int=array[1..9] of integer;
var
  m:array[1..20] of string[9];
  a:array[1..20] of int;
  b:int;
  n,i,j,ans:integer;
procedure dfs(k,s:integer;b:int);
var
  i:integer;
  t:boolean;
  sum:int;
begin
  if k=n+1 then
  begin
    if s>ans then ans:=s;
    exit;
  end;
  {write('     ');
  for i:=1 to 9 do write(' ',b[i]);
  writeln;}
  t:=false;
  for i:=9 downto 1 do
  begin
    sum[i]:=a[k][i]+b[i];
    if sum[i] div 10>0 then begin t:=true; break; end;
  end;
  if not t then begin {write('#',k,' ',s,'  '); for i:=1 to 9 do write(sum[i],' '); writeln;} dfs(k+1,s+1,sum); end;
  dfs(k+1,s,b);
end;
begin
  assign(input,'escape.in');
  assign(output,'escape.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    readln(m[i]);
    for j:=1 to length(m[i]) do begin val(m[i][j],a[i][9-length(m[i])+j]); end;
    //for j:=1 to 9 do write(a[i][j]);
    //writeln;
  end;
  for i:=1 to 9 do b[i]:=0;
  dfs(1,0,b);
  writeln(ans);
  close(input);
  close(output);
end.
