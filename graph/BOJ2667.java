import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/*  
 * BOJ2667.java
 * ������ȣ ���̱�
 * ����� ������ �� ������ ����, ������ ���� �� ������ ���� ���� ������������ ����϶�.
 * Lee Ha Yeong  
 * 2019.09.25
 */

public class BOJ2667 {
	// ������ ũ�� N, ���� ����Ʈ adjList, �湮 üũ visitedList
	public static int N;	
	public static ArrayList<Integer>[] adjList;
	public static boolean[][] visitedList;
	public static int count;
	public static ArrayList<Integer> totalList = new ArrayList<>();
	
	// ����� ���鼭 üũ�ϱ� ���� �迭
	public static int dx[] = {-1, 1, 0, 0};
	public static int dy[] = {0, 0, -1, 1};
	
	public static void dfs(int x, int y) {
		if(visitedList[x][y]) return;
		
		visitedList[x][y] = true;
		
		// ����� ���鼭 üũ�ؾ���
		for(int i = 0; i < 4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if(adjList[nx].get(ny) == 1 && visitedList[nx][ny] == false) {
					dfs(nx, ny);
					count++;
				}
			}
		}
		

	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);	
		N = scan.nextInt();
		
		// �� ��������Ʈ ����
		adjList = new ArrayList[N];
		visitedList = new boolean[N][N];
		String input;
		for(int i = 0; i < N; i++) {
			adjList[i] = new ArrayList<>();
			input = scan.next();
			for(int j = 0; j < input.length(); j++) {
				adjList[i].add(Character.getNumericValue(input.charAt(j)));
				visitedList[i][j] = false;
			}
		}
		
		// dfs
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				// ù �� ã��. 1�� ������ ���� Ž�� ����
				if(adjList[i].get(j) == 1 && visitedList[i][j] == false) {
					count = 1;
					dfs(i, j);
					totalList.add(count);
					count = 0;
				}
			}
		}
		
		// �����Ͽ� ���
		Collections.sort(totalList);
		System.out.println(totalList.size());
		for(int i = 0; i < totalList.size(); i++) {
			System.out.println(totalList.get(i));
		}
	}
}
