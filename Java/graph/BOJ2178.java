import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*  
 * BOJ2178.java
 * 미로 탐색
 * (1,1)부터 (N,M)까지 가는 최단거리
 * Lee Ha Yeong  
 * 2019.09.25
 */

public class BOJ2178 {
	// 미로 가로 N, 미로 세로 M, 미로 map
	static int N;
	static int M;
	static int[][] map;
	static boolean[][] visited;
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	
	
	public static void bfs(int x, int y) {
		Queue<Pair> queue = new LinkedList<>();
		
		queue.offer(new Pair(x, y));
		visited[x][y] = true;
		
		while(!queue.isEmpty()) {
			Pair out = queue.poll();
			x = out.getX();
			y = out.getY();
			
			// 상하좌우 확인
			for(int i = 0; i < 4; i++) {
				int x2 = x + dx[i];
				int y2 = y + dy[i];
				
				if(x2 >= 0 && y2 >= 0 && x2 < N && y2 < M) {
					if(map[x2][y2] == 1 && !visited[x2][y2]) {
						queue.offer(new Pair(x2, y2));
						visited[x2][y2] = true;
						map[x2][y2] = map[x][y] + 1;
					}
				}
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		M = scan.nextInt();
		
		// 미로 생성
		map = new int[N][M];
		visited = new boolean[N][M];
		for(int i = 0; i < N; i++) {
			String input = scan.next();
			for(int j = 0; j < M; j++) {
				map[i][j] = Character.getNumericValue(input.charAt(j));
			}
		}
		
		bfs(0,0);
		
		System.out.println(map[N-1][M-1]);
		
		scan.close();
	}
	
	// 좌표 쌍 저장을 위한 클래스
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