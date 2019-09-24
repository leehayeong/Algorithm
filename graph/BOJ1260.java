import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*  
 * BOJ1260.java
 * DFS�� BFS 
 * Lee Ha Yeong  
 * 2019.09.24
 */

public class BOJ1260 {
	// ������ ���� N, ������ ���� M, ���� ���� ��ȣ V
	public static int N, M, V;
	
	// �湮 üũ, ���� ����Ʈ, ť(BFS)
	public static boolean[] checked;
	public static ArrayList<Integer>[] adjList;

	// DFS ����
	public static void dfs(int start) {
		if(checked[start]) return;
		
		checked[start] = true;
		System.out.print(start + " ");
		
		for(int num : adjList[start]) {
			if(!checked[num]){
				dfs(num);
			}
		}
	}
	
	// BFS ����
	public static void bfs(int start) {
		Queue<Integer> queue = new LinkedList<>();
		
		queue.offer(start);
		checked[start] = true;
		
		while(!queue.isEmpty()) {
			int out = queue.poll();
			System.out.print(out + " ");
			
			for(int num : adjList[out]) {
				if(!checked[num]) {
					queue.offer(num);
					checked[num] = true;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		// ù �� �Է� (���� ��, ���� ��, ���� ����)
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		M = scan.nextInt();
		V = scan.nextInt();
		checked = new boolean[N+1];

		// �׷��� ����
		adjList = new ArrayList[N+1];
		for(int i = 0; i < N+1; i++) {
			adjList[i] = new ArrayList<>();
		}
		
		// ���� ����
		int n1, n2;
		for(int i = 0; i < M; i++) {
			n1 = scan.nextInt();
			n2 = scan.nextInt();
			adjList[n1].add(n2);
			adjList[n2].add(n1);
		}
		
		// ���� sort
		for(int i = 1; i <= N; i++) {
			Collections.sort(adjList[i]);
		}
		
		// DFS
		dfs(V);
		
		// checked �ʱ�ȭ
		for(int i = 0; i <= N; i++) {
			checked[i] = false;
		}
		System.out.println();
		
		// BFS
		bfs(V);
	}
}
