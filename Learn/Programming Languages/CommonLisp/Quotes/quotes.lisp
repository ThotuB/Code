(defvar num 3)

(print num)
(print '(num = num))
(print `(num = num))
(print `(num = ,num))
(print `(num = ,@num))

(defvar lst '(1 2 3))

(print lst)
(print '(lst = lst))
(print `(lst = lst))
(print `(lst = ,lst))
(print `(lst = ,@lst))