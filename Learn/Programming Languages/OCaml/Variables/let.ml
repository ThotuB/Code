(* Sequential *)
let a = "alpha"
let b = "beta"
let ab = a ^ ", " ^ b;;

Printf.printf "ab = %s\n" ab

(* Parallel *)
let c = "gamma"
and d = "delta"
and cd = "gamma, delta";;

Printf.printf "cd = %s\n" cd
