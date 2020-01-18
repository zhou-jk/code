program codevs_string1065_01_2016_12_4;
var
  s:string[30];
  ans:longint;
  n:integer;
procedure dfs(k:integer);
var
  i,j,l,m:integer;
begin
  if k=n+1 then
  begin
    inc(ans);
    exit;
  end;
  if (k<3)or(s[k-1]<>'0')or(s[k-2]<>'0')then begin s[k]:='0'; dfs(k+1); end;
  if (k<3)or(s[k-1]<>'1')or(s[k-2]<>'1')then begin s[k]:='1'; dfs(k+1); end;
end;
begin
  readln(n);
  if n=0 then begin writeln(0); exit; end;
  dfs(1);
  writeln(ans);
end.
