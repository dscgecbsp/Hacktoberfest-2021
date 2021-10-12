import java.util.Scanner;
 
public class Board {
 
    int chessBoard[][];
    int queens;
 
    public Board(int queens) {
        chessBoard = new int[20][20];
        this.queens = queens;
    }
 
    void displayBoard(){
        int i, j;
        for(i=0; i<queens; i++){
            for(j=0; j<queens; j++){
                if(chessBoard[i][j] == 1)
                    System.out.print(" * ");
                else
                    System.out.print(" - ");
            }
            System.out.print("\n");
        }
        System.out.print("\n");
        System.out.print("\n");
    }
 
    void reset(){
        for(int i=0; i<queens; i++){
            for(int j=0; j<queens; j++){
                chessBoard[i][j] = 0;
            }
        }
    }
 
    boolean isValidPlace(int row, int col){
        int i,j;
 
        //Checking horizontally
        for(i=col; i>=0; i--){
            if(chessBoard[row][i] == 1)
                return false;
        }
 
        //checking left diagonal
        for(i=row, j=col; i>=0 && j>=0; i--,j--){
            if(chessBoard[i][j] == 1)
                return false;
        }
 
        //checking right diagonal
        for(i=row, j=col; i<queens && j>=0; i++,j--){
            if(chessBoard[i][j] == 1)
                return false;
        }
 
        return true;
    }
}
 
public class NQueen {
 
    int queens;
    boolean flag;
    Board board;
 
    public NQueen(int queens) {
        this.flag = false;
        this.board = new Board(queens);;
        this.queens = queens;
    }
 
    void solveNqueen(){
 
        int i;
        //starting from (0,0) of the board
        hasSolution(0,0);
 
        //After running hasSolution() still flag == false
        //It means no Solution
        if(!flag)
            System.out.println("No Solution");
 
    }
 
    boolean hasSolution(int ctr, int colQueen){
 
        //Reached beyond last column
        //Means solution (configuration) found
 
        if(colQueen == queens){
            flag = true;
            board.displayBoard();
            //intentionally returning false to find more possible solution
            return false;
        }
 
        int i,j;
        for(i=ctr; i<queens; i++){
 
            //checking if position is safe
            if(board.isValidPlace(i,colQueen)){
                //setting current value to 1 means placing a queen
                board.chessBoard[i][colQueen] = 1;
                //moving to next column's 1st row
                if(hasSolution(0,colQueen+1))
                    return true;
 
                //backtrack
                //reset to 0 means removing queen
                board.chessBoard[i][colQueen] = 0;
            }
 
        }
 
        //When no row is safe in current column
        return false;
    }
}
 
public class App {
 
    static Scanner in = new Scanner(System.in);
 
    public static void main(String args[]){
        System.out.println("Enter number of Queens");
        int queens = in.nextInt();
 
        NQueen nQueen = new NQueen(queens);
        nQueen.solveNqueen();
 
    }
}
