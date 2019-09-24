import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/*  
 * BFS.java 
 * Lee Ha Yeong  
 * 2019.09.24
 * https://118k.tistory.com/263 ����
 */

public class BFS {
	// �׷��� �׸��� ���� ���: ��� ��, ���Ḯ��Ʈ
	// �湮 üũ�ϱ� ���� ���: üũ �迭, ť
	
	// ��� ��, ���Ḯ��Ʈ ����
	// ���ǻ�, ��带 1-7�� �ϱ� ����, �迭 0�� ������� �ʴ´ٰ� �����ϰ� V+1��ŭ�� ����Ʈ�迭 ����
	static int V = 7;
	static ArrayList<Integer>[] adjList = new ArrayList[V+1];

	// üũ �迭, ť ����
	static boolean[] checked = new boolean [V+1];
	static Queue<Integer> queue = new LinkedList<>();
	

	public static void bfs(int start) {
		// 1. ť�� ù ��� �����ϰ� �湮ǥ��
		queue.offer(start);
		checked[start] = true;
		
		// 2. ť���� ������ ������ ��� ť�� ����(ť�� �������� �ݺ�)
		while(!queue.isEmpty()) {
			int out = queue.poll();
			System.out.print(out + " ");
			
			// �̹� üũ �ƴٸ� ���� ����, üũ �ȵƴٸ� üũ�ϰ� ť�� ����
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
		// �׷��� ���� (0�� ������� �ʴ´�. 1-7���� ��� �߰�)
		// ��� 1 ����
		adjList[1] = new ArrayList<>();
		adjList[1].add(2);
		adjList[1].add(3);
		
		// ��� 2 ����
		adjList[2] = new ArrayList<>();
		adjList[2].add(1);
		adjList[2].add(4);
		adjList[2].add(5);
		
		// ��� 3 ����
		adjList[3] = new ArrayList<>();
		adjList[3].add(1);
		adjList[3].add(6);
		adjList[3].add(7);
		
		// ��� 4 ����
		adjList[4] = new ArrayList<>();
		adjList[4].add(2);
	
		// ��� 5 ����
		adjList[5] = new ArrayList<>();
		adjList[5].add(2);
		
		// ��� 6 ����
		adjList[6] = new ArrayList<>();
		adjList[6].add(3);
		
		// ��� 7 ����
		adjList[7] = new ArrayList<>();
		adjList[7].add(3);
		
		// bfs 
		bfs(1);
	}
}
