program h_1636_meiyoushangsidewuhui_DP_2017_4_22;
var
  mat:array[1..3000,0..2999] of integer;
  f:array[1..3000,0..1] of longint;
  b:array[1..3000] of boolean;
  r:array[1..3000] of integer;
  n,i,l,k,root:integer;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  max:=b;
end;
procedure dfs(k:integer);
var i,t:integer;
begin
  f[k,1]:=r[k];
  for i:=1 to mat[k,0] do
  begin
    t:=mat[k,i];
    dfs(t);
    inc(f[k,0],max(f[t,0],f[t,1]));
    inc(f[k,1],f[t,0]);
  end;
end;
begin
  readln(n);
  for i:=1 to n do read(r[i]);
  for i:=1 to n-1 do
  begin
    readln(l,k);
    inc(mat[k,0]);
    mat[k,mat[k,0]]:=l; b[l]:=true;
  end;
  readln(l,k);
  for i:=1 to n do
    if not b[i] then root:=i;
  dfs(root);
  writeln(max(f[root,0],f[root,1]));
end.
