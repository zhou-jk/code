program h_1957_shushi_2017_8_3;
type number=array[1..5] of byte;
var
  f:array[0..9] of boolean;
  n:array[1..9] of byte;
  m,i,j,k,p,q:byte;
  n1,n2,n3:number;
  ans:longint;
function plus(n1,n2:number):number;
var i,t:byte;
begin
  t:=0;
  for i:=5 downto 1 do
  begin
    plus[i]:=n1[i]+n2[i]+t;
    t:=plus[i]div 10;
    plus[i]:=plus[i]mod 10;
  end;
end;
function x(n1:byte;n2:number):number;
var i,t:byte;
begin
  t:=0;
  for i:=5 downto 1 do
  begin
    x[i]:=n1*n2[i]+t;
    t:=x[i]div 10;
    x[i]:=x[i]mod 10;
  end;
end;
function pd(n:number;l:byte):boolean;
var
  b:boolean;
  i,s:byte;
begin
  s:=0; b:=false;
  for i:=5 downto 1 do
  begin
    if n[i]>0
    then begin
           if b then exit(false);
           inc(s);
         end
    else b:=true;
    if not f[n[i]] then exit(false);
  end;
  if l=s then exit(true);
  exit(false);
end;
begin
  readln(m);
  for i:=1 to m do
  begin
    read(n[i]);
    f[n[i]]:=true;
  end;
  f[0]:=true;
  for i:=1 to m do
    for j:=1 to m do
      for k:=1 to m do
      begin
        n1[3]:=n[i]; n1[4]:=n[j]; n1[5]:=n[k];
        for p:=1 to m do
        begin
          n2:=x(n[p],n1);
          if pd(n2,3) then
            for q:=1 to m do
            begin
              n3:=x(n[q],n1);
              if pd(n3,3)and pd(plus(n2,x(10,n3)),4) then inc(ans);
                //writeln(i,' ',j,' ',k,' ',p,' ',q);
            end;
        end;
      end;
  writeln(ans);
end.
