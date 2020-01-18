program decorate_yh_h;
var
  t,next:array[1..200000] of longint;
  head,f:array[1..50000] of longint;
  n,m,i,a,b,nedge,tot,s,ans:longint;
procedure stop;
begin
  writeln(ans);
  close(input); close(output);
  halt;
end;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure addedge(a,b:longint);
begin
  inc(nedge);
  t[nedge]:=b; next[nedge]:=head[a]; head[a]:=nedge;
end;
procedure dfs(k:longint);
var v,p:longint;
begin
  if f[k]=1 then inc(s);
  inc(tot);
  p:=head[k];
  while p>0 do
  begin
    v:=t[p];
    if f[v]=-1
    then begin
           f[v]:=1-f[k];
           dfs(v);
         end
    else if f[v]=f[k] then
         begin
           ans:=-1;
           stop;
         end;
    p:=next[p];
  end;
end;
begin
  assign(input,'decorate.in'); assign(output,'decorate.out');
  reset(input); rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(a,b);
    addedge(a,b);
    addedge(b,a);
  end;
  fillchar(f,sizeof(f),255);
  for i:=1 to n do
    if f[i]=-1 then
    begin
      tot:=0; s:=0; f[i]:=1;
      dfs(i);
      inc(ans,max(s,tot-s));
    end;
  stop;
end.





