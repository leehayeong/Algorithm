import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*  
 * BOJ7576.java
 * 토마토
 * 상자 안에 들어있는 토마토가 모두 익을 때까지의 최소 날짜 출력
 * 처음부터 토마토가 다 익어있다면 0 출력
 * 토마토가 모두 익지 못하는 상황이면 -1 출력
 * Lee Ha Yeong  
 * 2019.09.28
 */

public class BOJ7576 {
	// 상자 크기 가로 M, 세로 N
	// 1은 익은 토마토, 0은 익지 않은 토마토, -1은 토마토가 없는 칸
	static int M;
	static int N;
	static int[][] box;
	static int[][] visited;
	static int[] dx = {1,-1,0,0};
	static int[] dy = {0,0,-1,1};
	static int day;
	
	public static void bfs() {
		Queue<Pair> queue = new LinkedList<>();
		Pair out;
		
		// 1. 첫째날 상자를 탐색하면서 익은 토마토가 있는 위치를 저장한다.
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(box[i][j] == 1) {	
					queue.offer(new Pair(i, j));
					visited[i][j] = 0;
				} else {
					visited[i][j] = -1;
				}
			}
		}
		
		// 2. 익은 토마토부터 시작한다.	
		int x2, y2;	
		while(!queue.isEmpty()) {
			out = queue.poll();
				
			for(int j = 0; j < 4; j++) {
				x2 = out.getX() + dx[j];
				y2 = out.getY() + dy[j];
					
				if(x2 >= 0 && y2 >= 0 && x2 < N && y2 < M) {
					if(box[x2][y2] == 0 && visited[x2][y2] == -1) {
						queue.offer(new Pair(x2, y2));
						visited[x2][y2] = visited[out.getX()][out.getY()] + 1;
					}
				}
			}
		}
	}
	
	public static void check() {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(box[i][j] == 0 && visited[i][j] == -1) {
					// 하나라도 방문하지 못한 곳이 있다면
					day = -1;
					return;
				}
				day = Math.max(day, visited[i][j]);
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		M = scan.nextInt();
		N = scan.nextInt();

		// 토마토 상자 생성
		box = new int[N][M];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				int x = scan.nextInt();
				box[i][j] = x;
			}
		}

		// 탐색 
		visited = new int[N][M];
		bfs();
		
		// 탐색 후 익지 않은 토마토가 있는지 확인
		check();
		System.out.println(day);
		
		scan.close();
	}	
	
	static class Pair{
		int x;
		int y;
		
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
		
		int getX() {
			return this.x;
		}
		
		int getY() {
			return this.y;
		}
	}
}