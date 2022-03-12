;; (((B A) (B A)) (((A B A B) (A B) A B) ((A B A B A B) (A B))))

(defvar L '(A B))

(print 
    (list (list (reverse L) (reverse L)) (list (append (list (append L L) L) L) (list (append L L L) L)))
)
