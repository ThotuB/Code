let rec factorial n =
    if n == 0 
        then 1 
        else n * factorial (n - 1)
;;

let n = 15;;
Printf.printf "%d! = %d\n" n (factorial n)