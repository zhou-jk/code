program h_1184_dancidehuafen_dongtaiguihua_2017_2_8;
var
  word:array[1..100] of string;
  f:array[0..100] of byte;
  s,s1:string;
  n,i,j:byte;
function min(a,b:byte):byte;
begin
  if a<b then exit(a);
  exit(b);
end;
begin
  readln(s);
  readln(n);
  for i:=1 to n do readln(word[i]);
  f[0]:=0;
  for i:=1 to length(s) do
  begin
    f[i]:=101;
    for j:=1 to n do
      if i>=length(word[j]) then
      begin
        //writeln(i,' ',j);
        s1:=copy(s,i-length(word[j])+1,length(word[j]));
        if s1=word[j] then f[i]:=min(f[i],f[i-length(word[j])]+1);
      end;
  end;
  writeln(f[i]);
end.


