public class Q5 {
    public static boolean issafe(int sudoku[][], int row, int col, int digit) {
        // for col
        for (int i = 0; i <= 8; i++) {
            if (sudoku[i][col] == digit) {
                return false;
            }
        }

        // for row
        for (int i = 0; i <= 8; i++) {
            if (sudoku[row][i] == digit) {
                return false;
            }
        }
        // for grid
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        // grid 3x3
        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (sudoku[i][j] == digit) {
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean sudokoSolver(int suduko[][], int row, int col) {
        // base case
        if(row == 9){
            return true;
        } 
        // going to next col and row.
        int nextrow = row, nextcol = col + 1;
        if(col+1 == 9) {
            nextrow = row + 1;
            nextcol = 0;
        }
        // checking if position is empty or not
        if (suduko[row][col] != 0) {
            return sudokoSolver(suduko, nextrow, nextcol);
        }
        //
        for (int digit = 1; digit <= 9; digit++) {
            if (issafe(suduko, row, col, digit)) {
                suduko[row][col] = digit;
                if (sudokoSolver(suduko, nextrow, nextcol)) {
                    return true;
                }
                suduko[row][col] = 0;
            }
        }
        return false;
    }
    public  static void print(int sudoku[][]){
        for(int i =0; i< sudoku.length; i++){
            for(int j =0; j<sudoku.length; j++){
                System.out.print(sudoku[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int sudoku[][] = { { 0, 0, 8, 0, 0, 0, 0, 0, 0 },
                { 4, 9, 0, 1, 5, 7, 0, 0, 2 },
                { 0, 0, 3, 0, 0, 4, 1, 9, 0 },
                { 1, 8, 5, 0, 6, 0, 0, 2, 0 },
                { 0, 0, 0, 0, 2, 0, 0, 6, 0 },
                { 9, 6, 0, 4, 0, 5, 3, 0, 0 },
                { 0, 3, 0, 0, 7, 2, 0, 0, 4 },
                { 0, 4, 9, 0, 3, 0, 0, 5, 7 },
                { 8, 2, 7, 0, 0, 9, 0, 1, 3 }
        };
       if( sudokoSolver(sudoku, 0,0)){
        System.out.println("Solution Exist");
        print(sudoku);
       }else{
        System.out.println("Solution does not Exist");
       }
    }
}
