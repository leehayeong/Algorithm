import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*  
 * BOJ1260.java
 * DFS와 BFS 
 * Lee Ha Yeong  
 * 2019.09.24
 */

public class BOJ1260 {
	// 정점의 개수 N, 간선의 개수 M, 시작 정점 번호 V
	public static int N, M, V;
	
	// 방문 체크, 인접 리스트, 큐(BFS)
	public static boolean[] checked;
	public static ArrayList<Integer>[] adjList;

	// DFS 구현
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
	
	// BFS 구현
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
		// 첫 줄 입력 (정점 수, 간선 수, 시작 정점)
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		M = scan.nextInt();
		V = scan.nextInt();
		checked = new boolean[N+1];

		// 그래프 생성
		adjList = new ArrayList[N+1];
		for(int i = 0; i < N+1; i++) {
			adjList[i] = new ArrayList<>();
		}
		
		// 간선 연결
		int n1, n2;
		for(int i = 0; i < M; i++) {
			n1 = scan.nextInt();
			n2 = scan.nextInt();
			adjList[n1].add(n2);
			adjList[n2].add(n1);
		}
		
		// 간선 sort
		for(int i = 1; i <= N; i++) {
			Collections.sort(adjList[i]);
		}
		
		// DFS
		dfs(V);
		
		// checked 초기화
		for(int i = 0; i <= N; i++) {
			checked[i] = false;
		}
		System.out.println();
		
		// BFS
		bfs(V);
	}
}
