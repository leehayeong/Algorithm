
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*  
 * BOJ1697.java
 * 숨바꼭질
 * 수빈이가 동생을 찾을 수 있는 가장 빠른 시간
 * 수빈이 걷기: 1초 후에 X+1 OR X-1
 * 수빈이 순간이동: 1초 후 2*X
 * Lee Ha Yeong  
 * 2019.09.28
 */

public class BOJ1697 {
	// 수빈이 N, 동생 K
	static int N, K;
	
	// 수빈이가 현재 몇 초에 있는지 표시하는 배열
	static int[] visited;
	
	
	// 수빈이의 위치인 N을 주었을 때,
	// N이 M에 도달했을 때 몇 초 걸리는지.
	public static void bfs(int start) {
		Queue<Integer> queue = new LinkedList<>();
		
		queue.offer(start);
		visited[start] = 0;
		
		while(!queue.isEmpty()) {
			int x = queue.poll();
			int nx;
			
			for(int i = 0; i < 3; i++) {
				if(i == 0) {
					nx = x + 1;
				} else if(i == 1) {
					nx = x - 1;
				} else {
					nx = x * 2;
				}
				
				if(nx >= 0 && nx <= 100000) {
					if(visited[nx] == -1) {
						queue.offer(nx);
						visited[nx] = visited[x]+1;
					} 
				}
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		K = scan.nextInt();
		
		visited = new int[100001];
		Arrays.fill(visited, -1);
		bfs(N);
		
		System.out.println(visited[K]);
		
		scan.close();
	}	
	

}