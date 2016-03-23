{ VERIFICATION PROGRAM for FLIP GAME problem for NEERC'2000 }
{ (C) Roman Elizarov }
{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
program FLIP_CHECK;
uses
  testlib, symbols;

var
  iouf, ians: longint;

function readAns(var stream: InStream): longint;
var
  s: string;
  i: longint;
  r: integer;
begin
  s := compress(stream.readString);
  if upstr(s) = 'IMPOSSIBLE' then 
    readAns := -1
  else begin
    val(s, i, r);
    if r <> 0 then 
      stream.Quit(_PE, 'Invalid answer string: ' + s);
    if i < 0 then
      stream.Quit(_PE, 'Negative number in answer: ' + s);
    readAns := i;
  end;
end;

begin
  ians:= readAns(ans);
  iouf:= readAns(ouf);
  if not ouf.seekeof then Quit(_PE, 'Extra data in file');
  if iouf <> ians then
    Quit(_WA, 'Wrong answer: ' + str(iouf,0) + ' <> ' + str(ians,0) +
      ' (-1 means impossible)');
  Quit(_OK, 'Ok');
end.
