program h_1004_xiangtiandenaiyou_SPFA_2017_5_13;
var
  d,g:array[1..800,0..800] of integer;
  n,p,c,num,i,j,k,l,r,min,ans:longint;
  m,d1:array[1..800] of longint;
  s:array[1..100000] of integer;
  b:array[1..800] of boolean;
begin
  readln(n,p,c);
  for i:=1 to n do
  begin
    readln(num);
    inc(m[num]);
  end;
  fillchar(d,sizeof(d),10);
  for i:=1 to c do
  begin
    readln(j,k,d[j,k]);
    d[k,j]:=d[j,k];
    inc(g[j,0]); g[j,g[j,0]]:=k;
    inc(g[k,0]); g[k,g[k,0]]:=j;
  end;
  ans:=maxlongint;
  for i:=1 to p do
  begin
    fillchar(b,sizeof(b),false); fillchar(d1,sizeof(d1),10);
    l:=1; r:=1; s[r]:=i; b[i]:=true; d1[i]:=0; min:=0;
    while l<=r do
    begin
      k:=s[l];
      inc(l);
      b[k]:=false;
      for j:=1 to g[k,0] do
        if d1[k]+d[k,g[k,j]]<d1[g[k,j]] then
        begin
          d1[g[k,j]]:=d1[k]+d[k,g[k,j]];
          if not b[g[k,j]] then
          begin
            inc(r);
            s[r]:=g[k,j]; b[g[k,j]]:=true;
          end;
        end;
    end;
    for j:=1 to p do inc(min,d1[j]*m[j]);
    if min<ans then ans:=min;
  end;
  writeln(ans);
end.

