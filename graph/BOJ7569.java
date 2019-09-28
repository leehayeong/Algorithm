import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*  
 * BOJ7569.java
 * �丶�� (3����)
 * ���� �ȿ� ����ִ� �丶�䰡 ��� ���� �������� �ּ� ��¥ ���
 * ó������ �丶�䰡 �� �;��ִٸ� 0 ���
 * �丶�䰡 ��� ���� ���ϴ� ��Ȳ�̸� -1 ���
 * Lee Ha Yeong  
 * 2019.09.28
 */

public class BOJ7569 {
	// ���� ũ�� ���� M, ���� N, ���� H
	// 1�� ���� �丶��, 0�� ���� ���� �丶��, -1�� �丶�䰡 ���� ĭ
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
		
		// 1. ù°�� ���ڸ� Ž���ϸ鼭 ���� �丶�䰡 �ִ� ��ġ�� �����Ѵ�.
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
		
		// 2. ���� �丶����� �����Ѵ�.	
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
						// �ϳ��� �湮���� ���� ���� �ִٸ�
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

		// �丶�� ���� ����
		box = new int[N][M][H];
		for(int k = 0; k < H; k++) {
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					int x = scan.nextInt();
					box[i][j][k] = x;
					
				}
			}
		}

		// Ž�� 
		visited = new int[N][M][H];
		bfs();
		
		// Ž�� �� ���� ���� �丶�䰡 �ִ��� Ȯ��
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