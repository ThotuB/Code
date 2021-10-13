(defvar input_stream 
    (open "Learn/Programming Languages/CommonLisp/IO/input.txt" 
        :direction :input
    )
)

(defvar output_stream 
    (open "Learn/Programming Languages/CommonLisp/IO/output.txt" 
        :direction :output
    )
)

(defparameter c 
    (read-line input_stream)
)

(write-line c output_stream)

(close input_stream)
(close output_stream)