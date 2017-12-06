-- module Warmup exposing (change, stripQuotes, powers, sumOfCubesOdd, daysBetween)

module Warmup exposing (powers)
-- import Regex exposing (replace)
-- import List exposing(head, tail, minimum, maximum)
-- import Tuple
--
-- divmod x y = x // y

powers : Int -> Int -> Result String  (List Int)
powers base limit =
  if base < 0 then
    Err "negative base"
  else
    Ok
      [5, 2]
