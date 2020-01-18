var
  s:array[0..50,0..50] of longint;
  n,i,j,k,p,q,l,a,s1,ans:longint;
begin
  assign(input,'farmer.in'); assign(output,'farmer.out');
  reset(input); rewrite(output);
  readln(n);
  for i:=1 to n do
    for j:=1 to n do
    begin
      read(a);
      s[i,j]:=s[i-1,j]+s[i,j-1]-s[i-1,j-1]+a;
    end;
  for i:=0 to n-1 do
    for j:=0 to n-1 do
      for k:=i+1 to n do
        for p:=j+1 to n do
        begin
          s1:=s[k,p]-s[i,p]-s[k,j]+s[i,j];
          for q:=0 to j-1 do
          begin
            for l:=0 to i-1 do
              if s[i,j]-s[l,j]-s[i,q]+s[l,q]=s1 then inc(ans);
            for l:=k+1 to n do
              if s[l,j]-s[k,j]-s[l,q]+s[k,q]=s1 then inc(ans);
          end;
        end;
  writeln(ans);
  close(input); close(output);
end.

