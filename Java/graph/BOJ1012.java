import java.util.ArrayList;
import java.util.Scanner;

/*  
 * BOJ1012.java
 * ��������
 * �ʿ��� �������� �� (������ ���ߵ� ���̿� ������ 1������ ������ �ȴ�.)
 * Lee Ha Yeong  
 * 2019.09.25
 */

public class BOJ1012 {
	// ���߹� ���� ���� M, ���߹� ���� ���� N, ���� ���� K
	static int M;
	static int N;
	static int K;
	static int[][] map;
	static boolean[][] visited;
	
	// ��� Ȯ���� ���� dx, dy �迭
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	
	public static void dfs(int x, int y) {
		if(visited[x][y]) return;
		
		visited[x][y] = true;
		
		// ��� Ȯ��
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
		
		// �׽�Ʈ���̽� �� T, ������ �� count, �׽�Ʈ���̽� ��� ������ �� ����Ʈ totalList
		int T = scan.nextInt();
		ArrayList<Integer> totalList = new ArrayList<>();
		
		for(int i = 0; i < T; i++) {
			M = scan.nextInt();
			N = scan.nextInt();
			K = scan.nextInt();
			int count = 0;
			
			// ���� �ɱ�
			map = new int[M][N];
			visited = new boolean[M][N];
			for(int j = 0; j < K; j++) {
				int x, y;
				x = scan.nextInt();
				y = scan.nextInt();
				map[x][y] = 1;
			}
			
			// ���߰� �ɾ����ִ� ù �κ� ã��
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
