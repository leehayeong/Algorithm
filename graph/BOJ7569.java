import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*  
 * BOJ7569.java
 * 토마토 (3차원)
 * 상자 안에 들어있는 토마토가 모두 익을 때까지의 최소 날짜 출력
 * 처음부터 토마토가 다 익어있다면 0 출력
 * 토마토가 모두 익지 못하는 상황이면 -1 출력
 * Lee Ha Yeong  
 * 2019.09.28
 */

public class BOJ7569 {
	// 상자 크기 가로 M, 세로 N, 높이 H
	// 1은 익은 토마토, 0은 익지 않은 토마토, -1은 토마토가 없는 칸
	static int M, N, H;
	static int[][][] box;
	static int[][][] visited;
	static int[] dx = {0,0,1,-1,0,0};
	static int[] dy = {1,-1,0,0,0,0};
	static int[] dz = {0,0,0,0,1,-1};
	static int day = 0;
	
	public static void bfs() {
		Queue<Pair> queue = new LinkedList<>();
		Pair out;
		
		// 1. 첫째날 상자를 탐색하면서 익은 토마토가 있는 위치를 저장한다.
		for(int k = 0; k < H; k++) {
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					if(box[i][j][k] == 1) {	
						queue.offer(new Pair(i, j, k));
						visited[i][j][k] = 0;
					} else {
						visited[i][j][k] = -1;
					}
				}
			}
		}
		
		// 2. 익은 토마토부터 시작한다.	
		int nx, ny, nz;	
		while(!queue.isEmpty()) {
			out = queue.poll();
				
			for(int j = 0; j < 6; j++) {
				nx = out.getX() + dx[j];
				ny = out.getY() + dy[j];
				nz = out.getZ() + dz[j];
					
				if(nx >= 0 && ny >= 0 && nz >= 0 &&
						nx < N && ny < M && nz < H) {
					if(box[nx][ny][nz] == 0 && visited[nx][ny][nz] == -1) {
						queue.offer(new Pair(nx, ny, nz));
						visited[nx][ny][nz] = visited[out.getX()][out.getY()][out.getZ()] + 1;
					}
				}
			}
		}
	}
	
	public static void check() {
		for(int k = 0; k < H; k++) {
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					if(box[i][j][k] == 0 && visited[i][j][k] == -1) {
						// 하나라도 방문하지 못한 곳이 있다면
						day = -1;
						return;
					}
					day = Math.max(day, visited[i][j][k]);
				}
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		M = scan.nextInt();
		N = scan.nextInt();
		H = scan.nextInt();

		// 토마토 상자 생성
		box = new int[N][M][H];
		for(int k = 0; k < H; k++) {
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					int x = scan.nextInt();
					box[i][j][k] = x;
					
				}
			}
		}

		// 탐색 
		visited = new int[N][M][H];
		bfs();
		
		// 탐색 후 익지 않은 토마토가 있는지 확인
		check();
		System.out.println(day);
		
		scan.close();
	}	
	
	static class Pair{
		int x;
		int y;
		int z;
		
		Pair(int x, int y, int z){
			this.x = x;
			this.y = y;
			this.z = z;
		}
		
		int getX() {
			return this.x;
		}
		
		int getY() {
			return this.y;
		}
		
		int getZ() {
			return this.z;
		}
	}
}