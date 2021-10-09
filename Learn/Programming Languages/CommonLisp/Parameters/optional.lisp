(defun power (x &optional y) ; default y = 1
    (if (not y)
        x
        (expt x y)
    )
)

(defun logarithm (nr &optional (base 2))
    (log nr base)
)

(print (power 3))
(print (power 3 2))

(print (logarithm 8))
(print (logarithm 8 4))
