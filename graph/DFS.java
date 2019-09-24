import java.util.ArrayList;

/*  
 * DFS.java 
 * Lee Ha Yeong  
 * 2019.09.24
 */

public class DFS {
	// �׷��� �׸��� ���� ���: ��� ��, ���Ḯ��Ʈ
	// �湮 üũ�ϱ� ���� ���: üũ �迭
	
	// ��� ��, ���Ḯ��Ʈ ����
	// ���ǻ�, ��带 1-7�� �ϱ� ����, �迭 0�� ������� �ʴ´ٰ� �����ϰ� V+1��ŭ�� ����Ʈ�迭 ����
	static int V = 7;
	static ArrayList<Integer>[] adjList = new ArrayList[V+1];

	// üũ �迭, ť ����
	static boolean[] checked = new boolean [V+1];
	

	public static void dfs(int node) {
		// ���� ��带 �̹� �湮�ߴٸ�, return�ؼ� �Լ��� ���� �� �ֵ���
		if(checked[node]) return;
		
		// ó�� �湮�ϴ� ���̶�� �湮ǥ��
		checked[node] = true;
		System.out.print(node + " ");
		
		// ������带 �ϳ��� �湮�ϸ鼭 ������带 ������� dfs ����
		for(int i = 0; i < adjList[node].size(); i++) {
			int nextNode = adjList[node].get(i);
			dfs(nextNode);
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
		adjList[2].add(3);
		adjList[2].add(4);
		adjList[2].add(5);
		
		// ��� 3 ����
		adjList[3] = new ArrayList<>();
		adjList[3].add(1);
		adjList[2].add(2);
		adjList[3].add(6);
		adjList[3].add(7);
		
		// ��� 4 ����
		adjList[4] = new ArrayList<>();
		adjList[4].add(2);
		adjList[4].add(5);
	
		// ��� 5 ����
		adjList[5] = new ArrayList<>();
		adjList[5].add(2);
		adjList[5].add(4);
		
		// ��� 6 ����
		adjList[6] = new ArrayList<>();
		adjList[6].add(3);
		adjList[6].add(7);
		
		// ��� 7 ����
		adjList[7] = new ArrayList<>();
		adjList[7].add(3);
		adjList[7].add(4);
		
		// dfs 
		dfs(1);
	}
}
