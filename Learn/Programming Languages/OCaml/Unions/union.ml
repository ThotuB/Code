type 'a node = 
    | Null
    | Node of {
        value: int;
        left: 'a node;
        right: 'a node
    }
;;

type expression = 
    | Value of float
    | Add of (expression * expression)
    | Sub of (expression * expression)
    | Mul of (expression * expression)
    | Div of (expression * expression)
    | Fn1 of ((float -> float) * expression)
    | Fn2 of ((float -> float -> float) * expression * expression)
;;