program cs_erfengchazhaocishu_2016_10_6(input,output);
uses math;
const n=100;
var
  b:array[1..1000] of integer;
  c:array[0..n] of boolean;
  d:boolean;
  i,j:integer;
function czcs(s,t:integer):integer;
var
  mid:integer;
begin
  mid:=(s+t) div 2;
  inc(i);
  b[i]:=mid;
  if s>t then exit(0);
  if s=t then exit(1);
  //else
  czcs:=max(czcs(s,mid-1),czcs(mid+1,t))+1;
end;
begin
  i:=0;
  writeln(czcs(1,n));
  for j:=1 to i do c[b[j]]:=true;
  d:=true;
  for j:=1 to n do
    if c[j]=false then begin d:=false; break; end;
  if d then  writeln('yes') else writeln('no');
  readln;
end.
