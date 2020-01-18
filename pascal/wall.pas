var
  p:array[1..400,1..400] of longint;
  f,f1,f2:array[0..400,0..401] of int64;
  c:array[1..400] of integer;
  n,m,k,i,j,ii:integer;
  ans,e:int64;
function min(a,b:int64):int64;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  assign(input,'wall.in'); assign(output,'wall.out');
  reset(input); rewrite(output);
  read(n,m,k);
  for i:=1 to n do read(c[i]);
  for i:=1 to n do
    for j:=1 to m do read(p[i,j]);
  fillchar(f,sizeof(f),127); fillchar(f1,sizeof(f1),127); fillchar(f2,sizeof(f2),127); fillchar(e,sizeof(e),127);
  fillchar(f[1],sizeof(f[1]),0);
  for i:=1 to n do
    if c[i]=0
    then for ii:=k downto 1 do
         begin
           for j:=1 to m do
           begin
             f[ii,j]:=min(f[ii,j],min(f1[ii-1,j-1],f2[ii-1,j+1]))+p[i,j];
             //writeln(i,' ',ii,' ',j,' ',f[ii,j],' ',f[ii,j],' ',f1[ii-1,j-1],' ',f2[ii-1,j+1]);
           end;
           f1[ii,0]:=e; f2[ii,m+1]:=e;
           for j:=1 to m do f1[ii,j]:=min(f[ii,j],f2[ii,j-1]);
           for j:=m downto 1 do f2[ii,j]:=min(f[ii,j],f2[ii,j+1]);
         end
    else for ii:=k downto 1 do
         begin
           f[ii,c[i]]:=min(f[ii,c[i]],min(f1[ii-1,j-1],f2[ii-1,j+1]));
           fillchar(f1,sizeof(f1),127); fillchar(f2,sizeof(f2),127);
           for j:=c[i]-1 downto 1 do f2[ii,j]:=f[ii,c[i]];
           for j:=c[i]+1 to m do f1[ii,j]:=f[ii,c[i]];
         end;
  ans:=f[k,1]; //write(f[k,1],' ');
  for i:=2 to m do
  begin
    ans:=min(ans,f[k,j]);
    //write(f[k,j],' ');
  end;
  //writeln;
  if ans>=e
  then write(-1)
  else write(ans);
  close(input); close(output);
end.