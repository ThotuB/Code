let my_not m = match m with
    | true -> false
    | false -> true
;;

let my_and m = match m with
    | (false, _) -> false
    | (_, false) -> false
    | _ -> true
;;

let xor_1 m = match m with
    | (true, true) -> false
    | (true, false) -> true
    | (false, true) -> true
    | (false, false) -> false
;;

let xor_2 m = match m with
    | (true, x) -> not x
    | (false, x) -> x
;;

let xor_3 m = match m with
    | (true, false) -> true
    | (false, true) -> true
    | _ -> false
;;

let is_digit d = match d with
    | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 -> true
    | _ -> false
;;

let test_binary = function
    | 0 | 1 -> true
    | _ -> false
;;

let rec length lst = match lst with
    | [] -> 0
    | head::tail -> 1 + length tail
;;