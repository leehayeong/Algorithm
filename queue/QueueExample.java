import java.util.LinkedList;
import java.util.Queue;

/*  
 * Queue.java 
 * Lee Ha Yeong  
 * 2019.09.24
 */

public class QueueExample {
	public static void main(String[] args) {
		Queue<Integer> queue = new LinkedList<>();
		queue.offer(7);	// 7
		queue.offer(5);	// 5 7
		queue.offer(4);	// 4 5 7
		System.out.println("poll:" + queue.poll());	// 4 5
		queue.offer(6);	// 6 4 5
		System.out.println("poll:" + queue.poll());	// 6 4
		while(!queue.isEmpty()) {
			System.out.println("peek:" + queue.peek());
			queue.poll();
		}
	}
}
