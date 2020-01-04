import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/*  
 * BOJ2667.java
 * 단지번호 붙이기
 * 연결된 집들을 한 단지로 묶고, 단지의 수와 각 단지에 속한 집을 오름차순으로 출력하라.
 * Lee Ha Yeong  
 * 2019.09.25
 */

public class BOJ2667 {
	// 지도의 크기 N, 인접 리스트 adjList, 방문 체크 visitedList
	public static int N;	
	public static ArrayList<Integer>[] adjList;
	public static boolean[][] visitedList;
	public static int count;
	public static ArrayList<Integer> totalList = new ArrayList<>();
	
	// 사방을 돌면서 체크하기 위한 배열
	public static int dx[] = {-1, 1, 0, 0};
	public static int dy[] = {0, 0, -1, 1};
	
	public static void dfs(int x, int y) {
		if(visitedList[x][y]) return;
		
		visitedList[x][y] = true;
		
		// 사방을 돌면서 체크해야함
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
		
		// 집 인접리스트 생성
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
				// 첫 집 찾기. 1인 곳부터 단지 탐색 시작
				if(adjList[i].get(j) == 1 && visitedList[i][j] == false) {
					count = 1;
					dfs(i, j);
					totalList.add(count);
					count = 0;
				}
			}
		}
		
		// 정렬하여 출력
		Collections.sort(totalList);
		System.out.println(totalList.size());
		for(int i = 0; i < totalList.size(); i++) {
			System.out.println(totalList.get(i));
		}
	}
}
