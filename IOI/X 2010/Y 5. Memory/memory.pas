unit memory;

interface

   procedure play;

implementation

   uses graderlib;
   procedure play;
      var i: longint;
      var a,b : char;
   begin
      for i:=1 to 10 do begin
         a := faceup(42);
         b := faceup(47);
      end;
   end;

begin
end.
