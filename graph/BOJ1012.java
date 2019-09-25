import java.util.ArrayList;
import java.util.Scanner;

/*  
 * BOJ1012.java
 * 유기농배추
 * 필요한 지렁이의 수 (인접한 배추들 사이에 지렁이 1개씩만 있으면 된다.)
 * Lee Ha Yeong  
 * 2019.09.25
 */

public class BOJ1012 {
	// 배추밭 가로 길이 M, 배추밭 세로 길이 N, 배추 개수 K
	static int M;
	static int N;
	static int K;
	static int[][] map;
	static boolean[][] visited;
	
	// 사방 확인을 위한 dx, dy 배열
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	
	public static void dfs(int x, int y) {
		if(visited[x][y]) return;
		
		visited[x][y] = true;
		
		// 사방 확인
		for(int i = 0; i < 4; i++) {
			int x2 = x+dx[i];
			int y2 = y+dy[i];
			
			if(x2 >= 0 && y2 >= 0 && x2 < M && y2 < N) {
				if(map[x2][y2] == 1 && visited[x2][y2] == false) {
					dfs(x2, y2);
				}
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		// 테스트케이스 수 T, 지렁이 수 count, 테스트케이스 결과 지렁이 수 리스트 totalList
		int T = scan.nextInt();
		ArrayList<Integer> totalList = new ArrayList<>();
		
		for(int i = 0; i < T; i++) {
			M = scan.nextInt();
			N = scan.nextInt();
			K = scan.nextInt();
			int count = 0;
			
			// 배추 심기
			map = new int[M][N];
			visited = new boolean[M][N];
			for(int j = 0; j < K; j++) {
				int x, y;
				x = scan.nextInt();
				y = scan.nextInt();
				map[x][y] = 1;
			}
			
			// 배추가 심어져있는 첫 부분 찾기
			for(int j = 0; j < M; j++) {
				for(int k = 0; k < N; k++) {
					if(map[j][k] == 1 && visited[j][k] == false) {
						dfs(j, k);
						count++;
					}
				}
			}
			
			totalList.add(count);
		}
		
		for(int i = 0; i < totalList.size(); i++) {
			System.out.println(totalList.get(i));
		}
	}
}
