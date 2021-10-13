; Do Until loop
(defun pow (base exponent) 
    (do (
        (res base (* base res)) ; initialization - update
        (ex 1 (1+ ex))
    )(
        (= ex exponent) ; end condition
        res             ; return value
    )
        (format t "~a ^ ~a = ~a~%" base ex res)
    )
)

; Copy-Paste
(do ((x 0 (1+ x))) ((= x 5))
    ; body
)

(print (pow 2 5))