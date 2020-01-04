  
/*  
 * QuickSort.java 
 * Lee Ha Yeong  
 * 2019.09.24
 */ 

public class QuickSort {
	public static void quickSort(int[] nums, int start, int end) {
		if(start >= end) {	// ���Ұ� 1���� ��� 
			return;
		}
		
		int pivot = start;	// �ǹ����� ù��° ����
		int i = start + 1;	// ���� �����-���������� �����ϸ� �ǹ����� ū ���� ã�� ���� �ε���
		int j = end;		// ������ �����-�������� �����ϸ� �ǹ����� ���� ���� ã�� ���� �ε���
		int tmp;
		
		while (i <= j) {	// �������� ���� ������ �ݺ�
			while(nums[i] <= nums[pivot] && i <= end) {	// �ǹ����� ū ���� ���������� ���������� �̵�
				i++;
			}
			while(nums[j] >= nums[pivot] && j > start) {	// �ǹ����� ���� ���� ���������� �������� �̵�
				j--;
			}
			if(i > j) {	// ������ ���¸� j,�ǹ� �ش� �� ��ü
				tmp = nums[j];
				nums[j] = nums[pivot];
				nums[pivot] = tmp;
			} else { // �������� �ʾҴٸ� i,j �ش� �� ��ü
				tmp = nums[j];
				nums[j] = nums[i];
				nums[i] = tmp;
			}
		}
		
		// �����Ͱ� �������� �������� ����
		// j�� �ǹ��� ��ü�����Ƿ� j�� �ǹ��� �ִ� ��ġ
		// �ǹ� �������� ����, ���������� ���� �������� ����
		quickSort(nums, start, j-1);
		quickSort(nums, j+1, end);
	}
	
	public static void printArr(int[] arr) {
		for(int i = 0; i < arr.length; i++) { 
			System.out.print(arr[i] + " "); 
		} 
	}
	
	public static void main(String[] args) {
		int[] nums = {1, 4, 3, 10, 9, 2, 6, 8, 7, 5}; 
		
		// ������ �� �迭 ��� 
		System.out.print("BEFORE: "); 
		printArr(nums);

		// ������
		System.out.println("\nQUICK SORT"); 
		quickSort(nums, 0, nums.length-1);

		// ������ �� �迭 ��� 
		System.out.print("AFTER: "); 
		printArr(nums);
	}

}
