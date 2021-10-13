let inc = function x -> 
    x + 1
;;

Printf.printf "inc: %d\n" (inc 3)

let add_nums = function x -> 
    function y -> 
        x + y
;;

Printf.printf "add_nums: %d\n" (add_nums 2 3)

let add_tuple = function (x, y) -> 
    x + y
;;

Printf.printf "add_tuple: %d\n" (add_tuple (3, 4))