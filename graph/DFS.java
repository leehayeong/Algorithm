import java.util.ArrayList;

/*  
 * DFS.java 
 * Lee Ha Yeong  
 * 2019.09.24
 */

public class DFS {
	// 그래프 그리기 위한 요소: 노드 수, 연결리스트
	// 방문 체크하기 위한 요소: 체크 배열
	
	// 노드 수, 연결리스트 선언
	// 편의상, 노드를 1-7로 하기 위해, 배열 0은 사용하지 않는다고 가정하고 V+1만큼의 리스트배열 생성
	static int V = 7;
	static ArrayList<Integer>[] adjList = new ArrayList[V+1];

	// 체크 배열, 큐 선언
	static boolean[] checked = new boolean [V+1];
	

	public static void dfs(int node) {
		// 현재 노드를 이미 방문했다면, return해서 함수를 끝낼 수 있도록
		if(checked[node]) return;
		
		// 처음 방문하는 것이라면 방문표시
		checked[node] = true;
		System.out.print(node + " ");
		
		// 인접노드를 하나씩 방문하면서 인접노드를 대상으로 dfs 시행
		for(int i = 0; i < adjList[node].size(); i++) {
			int nextNode = adjList[node].get(i);
			dfs(nextNode);
		}
	}

	public static void main(String[] args) {
		// 그래프 생성 (0은 사용하지 않는다. 1-7까지 노드 추가)
		// 노드 1 생성
		adjList[1] = new ArrayList<>();
		adjList[1].add(2);
		adjList[1].add(3);
		
		// 노드 2 생성
		adjList[2] = new ArrayList<>();
		adjList[2].add(1);
		adjList[2].add(3);
		adjList[2].add(4);
		adjList[2].add(5);
		
		// 노드 3 생성
		adjList[3] = new ArrayList<>();
		adjList[3].add(1);
		adjList[2].add(2);
		adjList[3].add(6);
		adjList[3].add(7);
		
		// 노드 4 생성
		adjList[4] = new ArrayList<>();
		adjList[4].add(2);
		adjList[4].add(5);
	
		// 노드 5 생성
		adjList[5] = new ArrayList<>();
		adjList[5].add(2);
		adjList[5].add(4);
		
		// 노드 6 생성
		adjList[6] = new ArrayList<>();
		adjList[6].add(3);
		adjList[6].add(7);
		
		// 노드 7 생성
		adjList[7] = new ArrayList<>();
		adjList[7].add(3);
		adjList[7].add(4);
		
		// dfs 
		dfs(1);
	}
}
