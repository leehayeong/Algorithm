
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*  
 * BOJ1697.java
 * ���ٲ���
 * �����̰� ������ ã�� �� �ִ� ���� ���� �ð�
 * ������ �ȱ�: 1�� �Ŀ� X+1 OR X-1
 * ������ �����̵�: 1�� �� 2*X
 * Lee Ha Yeong  
 * 2019.09.28
 */

public class BOJ1697 {
	// ������ N, ���� K
	static int N, K;
	
	// �����̰� ���� �� �ʿ� �ִ��� ǥ���ϴ� �迭
	static int[] visited;
	
	
	// �������� ��ġ�� N�� �־��� ��,
	// N�� M�� �������� �� �� �� �ɸ�����.
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