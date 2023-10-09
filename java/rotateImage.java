class Solution {
    public void rotate(int[][] matrix) {
        int copyLength=matrix.length;  // This is n * n matrix so, we don't need column length 
        // First we have to convert row --> column
        for(int i=0;i<copyLength;i++){
            for(int j=i;j<copyLength;j++){
                int temp =matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }  
        // now we have to reverse the array.
        for(int i=0;i<copyLength;i++){
            for(int j=0;j<copyLength/2;j++){
                int temp = matrix[i][j];
                matrix[i][j]=matrix[i][copyLength-1-j];
                matrix[i][copyLength-1-j]=temp;
            }
        }
    }
}