; Map function
(defvar lst '(1 2 3 4 5))
(defun is_even (num)
    (if (zerop (rem num 2))
        1
        0
    )
)

(print (map 'list '1+ lst))
(print (mapc '1+ lst))
(print (mapcar '1+ lst))    ; new list from results of f(lst[i])
(print (mapcan '1+ lst))
; (print (mapcon 'is_even lst))
; (print (mapl 'is_even lst))