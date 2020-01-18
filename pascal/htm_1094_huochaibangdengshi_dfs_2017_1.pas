program htm_1094_huochaibangdengshi_dfs_2017_1_25;
var
  a:array[0..9] of byte;
  n:byte;
begin
  a[0]:=4; a[1]:=2; a[2]:=5; a[3]:=5; a[4]:=4; a[5]:=5; a[6]:=6; a[7]:=3; a[8]:=7; a[9]:=6;
  readln(n);
  dec(n,4);
  dfs1(
