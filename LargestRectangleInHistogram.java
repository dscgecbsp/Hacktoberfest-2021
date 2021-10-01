import java.util.Stack;

public class LargestRectangleInHistogram
{
    public int largestRectangleArea(int[] hist) {
        int n = hist.length, maxArea = 0;
        Stack<Integer>stack = new Stack<>();
        int i = 0;
        while(i < n){
            if(stack.isEmpty() || hist[i] >= hist[stack.peek()])
                stack.push(i++);
            else{
                int top = stack.peek();
                stack.pop();
                int currArea = hist[top]*(stack.isEmpty()?i:i-stack.peek()-1);
                maxArea = Math.max(maxArea, currArea);
            }
        }
        while(!stack.isEmpty()){
            int top = stack.peek();
            stack.pop();
            int currArea = hist[top]*(stack.isEmpty()?i:i-stack.peek()-1);
            maxArea = Math.max(maxArea, currArea);
        }
        return maxArea;
        
    }
}
