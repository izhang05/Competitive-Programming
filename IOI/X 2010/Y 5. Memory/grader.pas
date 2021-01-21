program grader;
   uses gradershare, memory;
   procedure playgame;
      var i: longint;
   begin
      candies := 0;
      moves := 0;
      for i:=1 to 50 do read(card[i]);
      play;
      if candies <> 25 then halt(91);
   end;
begin
   playgame;
   writeln('OK ',moves);
end.
