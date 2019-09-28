import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*  
 * BOJ7576.java
 * �丶��
 * ���� �ȿ� ����ִ� �丶�䰡 ��� ���� �������� �ּ� ��¥ ���
 * ó������ �丶�䰡 �� �;��ִٸ� 0 ���
 * �丶�䰡 ��� ���� ���ϴ� ��Ȳ�̸� -1 ���
 * Lee Ha Yeong  
 * 2019.09.28
 */

public class BOJ7576 {
	// ���� ũ�� ���� M, ���� N
	// 1�� ���� �丶��, 0�� ���� ���� �丶��, -1�� �丶�䰡 ���� ĭ
	static int M;
	static int N;
	static int[][] box;
	static boolean[][] visited;
	static int[] dx = {1,-1,0,0};
	static int[] dy = {0,0,-1,1};
	
	// ���� �� �� 
	static int day = 0;
	
	public static void search() {

	}
	
	public static void bfs() {
		Queue<Pair> queue = new LinkedList<>();
		Pair out;
		ArrayList<Integer> count = new ArrayList<>();
		int c = 0;
		
		// 1. ù°�� ���ڸ� Ž���ϸ鼭 ���� �丶�䰡 �ִ� ��ġ�� �����Ѵ�.
		// ���� �丶�䰡 �ִ� ��ġ ����
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(box[i][j] == 1) {	
					queue.offer(new Pair(i, j));
					visited[i][j] = true;
					c++;
				}
			}
		}
		count.add(c);
		
		// ���� �丶����� �����Ѵ�.
		// ť�� �ְ�, ���鼭 ���� �丶�� �� ���� ���� �� �ٽ� ť�� ����.
		// ť�� ���� Ƚ����ŭ ���� �� �ݺ��ؾ� ��.	
		int x2, y2;	
		while(!queue.isEmpty()) {
			c = 0;
			for(int i = 0; i < count.get(day); i++) {
				out = queue.poll();
				
				for(int j = 0; j < 4; j++) {
					x2 = out.getX() + dx[j];
					y2 = out.getY() + dy[j];
					
					if(x2 >= 0 && y2 >= 0 && x2 < N && y2 < M) {
						if(box[x2][y2] == 0 && !visited[x2][y2]) {
							queue.offer(new Pair(x2, y2));
							visited[x2][y2] = true;
							c++;
						} else if(box[x2][y2] == -1) {
							
						}
					}
				}
			}
			day++;
			count.add(c);
		}
		day--;
		
		// Ž�� �� ���� ���� �丶�䰡 �ִ��� Ȯ��
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(box[i][j] == 0 && !visited[i][j]) {
					// �ϳ��� �湮���� ���� ���� �ִٸ�
					day = -1;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		M = scan.nextInt();
		N = scan.nextInt();

		// �丶�� ���� ����
		box = new int[N][M];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				int x = scan.nextInt();
				box[i][j] = x;
			}
		}

		// Ž�� 
		visited = new boolean[N][M];
		bfs();
	
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