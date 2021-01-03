class Matrix {
    private final int rows;
    private final int cols;
    private int[][] data;

    // CONSTRUCTORS
    public Matrix(final int rows, final int cols){
        this.rows = rows;
        this.cols = cols;
        data = new int[rows][cols];
    }

    public Matrix(final int size){
        this(size, size);
    }

    // GETTERS
    public int rows(){
        return rows;
    }

    public int cols(){
        return cols;
    }

    public int[][] getAll(){
        return data;
    }

    // GET & SET
    public int get(int row, int col){
        return data[row][col]; 
    }

    public void set(int val, int row, int col){
        data[row][col] = val; 
    }

    // OPERATIONS
    public void add(Matrix Mat){
        if ( this.rows() != Mat.rows() || )
    }

    // TOSTRING & EQUALS
    public String toString(){
        String printString = "";
        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j < cols ; j++){
                printString += data[i][j] + " ";
            }
            printString += "\n";
        }
        return printString;
    }

    public boolean equals(Object o){
        if ( o instanceof Matrix ){
            if ( rows == ((Matrix)o).rows() && cols == ((Matrix)o).cols() ){
                return data.equals( ((Matrix)o).getAll() );
            }
        }

        return false;
    }

    // MAIN
    public static void main(String[] args){
        Matrix mat1 = new Matrix(3, 2);

        mat1.get(1,1);

        System.out.println(mat1.get(1,1));
    }
}