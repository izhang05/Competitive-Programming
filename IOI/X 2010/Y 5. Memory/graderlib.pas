unit graderlib;

interface
   function faceup(C: longint): char;

implementation
   uses gradershare;
   function faceup(C: longint): char;
   var c0, c1 : char;
   begin
      if (C < 1) or (C >50) or is_up[C] then begin
         halt(92);
      end;
      is_up[C] := true;
      up[moves mod 2] := C;
      moves := moves + 1;
      if (moves mod 2) = 0 then begin
         c0 := card[ up[0] ];
         c1 := card[ up[1] ];
         if (c0=c1) and (not candy[c0]) then begin
            candy[c0] := true;
            candies := candies + 1;
         end;
         is_up[ up[0] ] := false;
         is_up[ up[1] ] := false;
      end;
      faceup := card[C];
   end;

begin
end.
