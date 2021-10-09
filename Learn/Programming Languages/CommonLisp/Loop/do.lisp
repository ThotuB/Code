; Do Until loop
(do (
        (x 0 (1+ x)) ; initialize - update
    )
    (
        (= x 5) ; condition: true -> exit
    )
    (format t "x = ~a~%" x)
)

(do (
        (x 0 (1+ x)) ; multiple initializations
        (y 0 (1+ y))
    )
    (
        (= x 5) ; multiple conditions
        (= y 10) ; first condition: true -> exit
    )
    (format t "x = ~a  y = ~a~%" x y)
)

; Copy-Paste
(do ((x 0 (1+ x))) ((= x 5))
    (format t "x = ~a~%" x)
)