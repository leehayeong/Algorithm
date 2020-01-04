import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/*  
 * BFS.java 
 * Lee Ha Yeong  
 * 2019.09.24
 * https://118k.tistory.com/263 참조
 */

public class BFS {
	// 그래프 그리기 위한 요소: 노드 수, 연결리스트
	// 방문 체크하기 위한 요소: 체크 배열, 큐
	
	// 노드 수, 연결리스트 선언
	// 편의상, 노드를 1-7로 하기 위해, 배열 0은 사용하지 않는다고 가정하고 V+1만큼의 리스트배열 생성
	static int V = 7;
	static ArrayList<Integer>[] adjList = new ArrayList[V+1];

	// 체크 배열, 큐 선언
	static boolean[] checked = new boolean [V+1];
	static Queue<Integer> queue = new LinkedList<>();
	

	public static void bfs(int start) {
		// 1. 큐에 첫 노드 삽입하고 방문표시
		queue.offer(start);
		checked[start] = true;
		
		// 2. 큐에서 꺼내고 인접한 노드 큐에 삽입(큐가 빌때까지 반복)
		while(!queue.isEmpty()) {
			int out = queue.poll();
			System.out.print(out + " ");
			
			// 이미 체크 됐다면 다음 노드로, 체크 안됐다면 체크하고 큐로 삽입
			for(int i = 0; i < adjList[out].size(); i++) {
				int adjcheck = adjList[out].get(i);
				if(checked[adjcheck] == false) {
					queue.offer(adjcheck);
					checked[adjcheck] = true;
				}
			}
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
		adjList[2].add(4);
		adjList[2].add(5);
		
		// 노드 3 생성
		adjList[3] = new ArrayList<>();
		adjList[3].add(1);
		adjList[3].add(6);
		adjList[3].add(7);
		
		// 노드 4 생성
		adjList[4] = new ArrayList<>();
		adjList[4].add(2);
	
		// 노드 5 생성
		adjList[5] = new ArrayList<>();
		adjList[5].add(2);
		
		// 노드 6 생성
		adjList[6] = new ArrayList<>();
		adjList[6].add(3);
		
		// 노드 7 생성
		adjList[7] = new ArrayList<>();
		adjList[7].add(3);
		
		// bfs 
		bfs(1);
	}
}
