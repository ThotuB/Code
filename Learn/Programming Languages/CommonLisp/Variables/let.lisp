; LET* - sequential
(let* (
    (a 'alpha)
    (b 'beta)
    (ab (list a b))
)
    (print ab)
)

; LET - parallel
(let (
    (c 'gamma)
    (d 'delta)
    (cd (list 'c 'd))
)
    (print cd)
)