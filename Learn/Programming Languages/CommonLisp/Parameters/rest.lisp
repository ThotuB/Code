(defun add (&rest r)
    (cond
        ((null r)
            nil
        )
        (t
            (apply '+ r)
        )
    )
)

(print (add 1 2 3 4 5))