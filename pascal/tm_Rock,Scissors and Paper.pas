var
  a,i,j:longint;
  g:string;
  f:array[1..100] of longint;
  d,e:char;
begin
  readln(a);
  for i:=1 to a do
    begin
      readln(g);
      for j:=1 to length(g)-4 do
        if g[j]=' ' then
          begin
            d:=g[1];
            e:=g[j+1];
            break;
          end;
      case d of
        'R':case e of
              'R':f[i]:=0;
              'S':f[i]:=1;
              'P':f[i]:=2;
            end;
        'S':case e of
              'R':f[i]:=2;
              'S':f[i]:=0;
              'P':f[i]:=1;
              end;
        'P':case e of
              'R':f[i]:=1;
              'S':f[i]:=2;
              'P':f[i]:=0;
            end;
      end;
    end;
  for i:=1 to a do
    case f[i] of
      0:writeln('Tie');
      1:writeln('Player1');
      2:writeln('Player2');
    end;
  readln;
end.
