import java.util.Stack;

/*  
 * Stack.java 
 * Lee Ha Yeong  
 * 2019.09.24
 */

public class StackExample {
	public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(7);								// 7
        stack.push(5);								// 7 5
        stack.push(4);								// 7 5 4
        System.out.println("pop:" + stack.pop());	// 7 5
        stack.push(6);								// 7 5 6
        System.out.println("pop:" + stack.pop());	// 7 5
        while(!stack.empty()) {						
        	System.out.println("peek:" + stack.peek());
        	stack.pop();
        }
	}

}
