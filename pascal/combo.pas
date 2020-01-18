var
  a,b:array[1..3] of longint;
  n,i,j,k,ans:longint;
function p11:boolean;
begin
  exit((abs(i-a[1])<=2)or(i+n-a[1]<=2)or(a[1]+n-i<=2));
end;
function p12:boolean;
begin
  exit((abs(j-a[2])<=2)or(j+n-a[2]<=2)or(a[2]+n-j<=2));
end;
function p13:boolean;
begin
  exit((abs(k-a[3])<=2)or(k+n-a[3]<=2)or(a[3]+n-k<=2));
end;
function p1:boolean;
begin
  exit(p11 and p12 and p13);
end;
function p21:boolean;
begin
  exit((abs(i-b[1])<=2)or(i+n-b[1]<=2)or(b[1]+n-i<=2));
end;
function p22:boolean;
begin
  exit((abs(j-b[2])<=2)or(j+n-b[2]<=2)or(b[2]+n-j<=2));
end;
function p23:boolean;
begin
  exit((abs(k-b[3])<=2)or(k+n-b[3]<=2)or(b[3]+n-k<=2));
end;
function p2:boolean;
begin
  exit(p21 and p22 and p23);
end;
begin
  assign(input,'combo.in'); assign(output,'combo.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to 3 do read(a[i]);
  for i:=1 to 3 do read(b[i]);
  for i:=1 to n do
    for j:=1 to n do
      for k:=1 to n do
        if p1 or p2 then inc(ans);
  writeln(ans);
  close(input); close(output);
end.