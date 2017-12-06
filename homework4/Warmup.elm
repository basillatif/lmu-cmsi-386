-- module Warmup exposing (change, stripQuotes, powers, sumOfCubesOdd, daysBetween)

module Warmup exposing (..)
-- import Regex exposing (replace)
-- import List exposing(isOdd)
-- import Tuple
--
-- divmod x y = x // y

powers : Int -> Int -> Result String (List Int)
powers base limit =
  if base < 0 then
    Err "negative base"
  else
    Ok
      <| List.map (\power -> base ^ power) (List.range 0 <| floor <| logBase (toFloat base) (toFloat limit))


change : Int -> Result String (Int, Int, Int, Int)
change amount =
  if amount < 0 then
    Err "amount cannot be negative"
  else
    Ok <|
      let
        a = amount
        b = a % 25
        c = b % 10
        d = c % 5
      in
        (,,,) (a // 25) (b // 10) (c // 5) (d)


sumOfCubesOfOdds : List Int -> Int
sumOfCubesOfOdds list =
  List.filter (\a -> a % 2 /= 0) list |>  List.map (\a -> a ^ 3) |> List.foldr (+) 0
