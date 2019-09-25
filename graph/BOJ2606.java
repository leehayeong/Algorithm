
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*  
 * BOJ2606.java
 * 바이러스
 * 한 대의 컴퓨터가 바이러스에 걸렸을 때 감염되는 컴퓨터의 수를 구하라. 
 * Lee Ha Yeong  
 * 2019.09.25
 */

public class BOJ2606 {
	// 컴퓨터 수 N, 연결된 컴퓨터 쌍의 수 E, 바이러스에 감염된 컴퓨터 수 COUNT
	public static int N;
	public static int E;
	public static int COUNT = -1;

	// 컴퓨터 연결그래프, 방문 체크 배열
	public static ArrayList<Integer>[] adjList;
	public static boolean visited[];
	
	public static void bfs(int start) {
		Queue<Integer> queue = new LinkedList<>();
		
		visited[start] = true;
		queue.add(start);
		
		while(!queue.isEmpty()) {
			int out = queue.poll();
			COUNT++;
			// System.out.println(out + " ");
			
			for(int num : adjList[out]) {
				if(!visited[num]) {
					visited[num] = true;
					queue.add(num);
				}
			}
		}
		
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);	
		N = scan.nextInt();
		E = scan.nextInt();
		
		// 인접리스트 생성
		adjList = new ArrayList[N+1];
		for(int i = 1; i < N+1; i++) {
			adjList[i] = new ArrayList<>();
		}
		for(int i = 0; i < E; i++) {
			int n1 = scan.nextInt();
			int n2 = scan.nextInt();
			adjList[n1].add(n2);
			adjList[n2].add(n1);
		}
		for(int i = 1; i < N+1; i++) {
			Collections.sort(adjList[i]);
		}
		
		// bfs
		visited = new boolean[N+1];
		bfs(1);
		
		// 감염된 컴퓨터의 수 출력
		System.out.println(COUNT);
	}
}
