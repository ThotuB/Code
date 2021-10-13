let inc = fun x -> 
    x + 1
;;

Printf.printf "inc: %d\n" (inc 3)

let add_nums = fun x y -> 
    x + y
;;

Printf.printf "add_nums: %d\n" (add_nums 2 3)

let add_tuple = fun (x, y) -> 
    x + y
;;

Printf.printf "add_tuple: %d\n" (add_tuple (3, 4))