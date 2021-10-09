(defun div3 (num)
    (zerop (rem num 3))
)

(print
    (div3 12)
)

(print 
    (funcall
        (defun div3 (num)
            (zerop (rem num 3))
        )
    12
    )
)

(print 
    (funcall
        (lambda (num)
            (zerop (rem num 3))
        )
    12
    )
)