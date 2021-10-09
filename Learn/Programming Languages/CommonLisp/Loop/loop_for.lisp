(loop for x from 0 to 5
    do (format t "x = ~a~%" x)
)

(loop for x from 0 to 5 if (evenp x)
    do (format t "y = ~a~%" x)
)