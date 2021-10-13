type complex = {real: int; imag: int};;

let add = fun num1 num2 ->
    {real = num1.real + num2.real; imag = num1.imag + num2.imag};
;;

let num1 = {real = 1; imag = 2};;
let num2 = {real = 3; imag = 4};;

let result = add num1 num2;;

Printf.printf "result: (%d, %d)" result.real result.imag;;