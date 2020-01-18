
Var 
  a: array[1..200] Of longint;
  i: longint;
Begin
  a[1] := 1;
  a[2] := 1;
  For i:=3 To 20 Do
    a[i] := a[i-1]+a[i-2];
  writeln(a[20]);
  readln;
End.
