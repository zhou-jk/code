program codevs_erchashudexubianli3143_shu_2016_12_18;
var
  t:array[1..16] of record
                    l:integer;
                    r:integer;
  end;
  n,i:integer;
procedure dfs1(k:integer);
begin
  write(k,' ');
  if t[k].l>0 then dfs1(t[k].l);
  if t[k].r>0 then dfs1(t[k].r);
end;
procedure dfs2(k:integer);
begin
  if t[k].l>0 then dfs2(t[k].l);
  write(k,' ');
  if t[k].r>0 then dfs2(t[k].r);
end;
procedure dfs3(k:integer);
begin
  if t[k].l>0 then dfs3(t[k].l);
  if t[k].r>0 then dfs3(t[k].r);
  write(k,' ');
end;
begin
  readln(n);
  for i:=1 to n do readln(t[i].l,t[i].r);
  dfs1(1); writeln;
  dfs2(1); writeln;
  dfs3(1); writeln;
end.
