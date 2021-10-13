; Map function
(defvar lst1 '(1 2 3))
(defvar lst2 '(A B C))

(format t "mapc   : ~a~%" (mapc   'list lst1 lst2))     ; map(fn, ...param_lists)       -> List 1
(format t "mapcar : ~a~%" (mapcar 'list lst1 lst2))     ; map(fn, ...param_lists)       -> Result List
(format t "mapcan : ~a~%" (mapcan 'list lst1 lst2))     ; apply('nconc, map())          -> Conc'd List

(format t "mapl   : ~a~%" (mapl    'list lst1 lst2))    ; maplist(fn, ...param_lists)   -> List 1
(format t "maplist: ~a~%" (maplist 'list lst1 lst2))    ; maplist(fn, ...param_lists)   -> Result List
(format t "mapcon : ~a~%" (mapcon  'list lst1 lst2))    ; apply('nconc, maplist())      -> Conc'd List