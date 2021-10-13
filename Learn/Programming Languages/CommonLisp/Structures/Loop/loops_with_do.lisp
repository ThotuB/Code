; do until
(do (
    (x 1 (1+ x))
)(
    (>= x 10)
)
    (print x)
)

; do while
(do (
    (x 1 (1+ x))
)(
    (not (< x 10))
)
    (print x)
)