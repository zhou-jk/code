program codevs_1501erchashuzuidakuanduhegaodu_shu_2016_12_25;
var
  t:array[1..16] of record
                      l,r:integer;
                    end;
  b:array[1..16] of integer;
  n,i,ad,ab:integer;
procedure dfs(k,d:integer);
begin
  if d>ad then ad:=d;
  inc(b[d]);
  if t[k].l>0 then dfs(t[k].l,d+1);
  if t[k].r>0 then dfs(t[k].r,d+1);
end;
begin
  readln(n);
  for i:=1 to n do readln(t[i].l,t[i].r);
  dfs(1,1);
  for i:=1 to n do if b[i]>ab then ab:=b[i];
  writeln(ab,' ',ad);
end.


