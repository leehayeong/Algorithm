  
/*  
 * InsertionSort.java 
 * Lee Ha Yeong  
 * 2019.09.24
 */ 

public class InsertionSort {
	public static void insertionSort(int[] nums) {
		int i, j, tmp;
		for(i = 0; i < nums.length-1; i++) {
			j = i;			
			// ���� ��ġ���� ���� ���ҿ� ��. 
			// �̹� ���ĵǾ��ִٸ� �� ���ұ����� �� ���ĵǾ� �ִ� ��.
			while(nums[j] > nums[j+1]) {	
				tmp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = tmp;
				j--;	// �������� ���� ��ġ ã�ư��� ���� ��
			}
		}
	}
	
	public static void printArr(int[] arr) {
		for(int i = 0; i < arr.length; i++) { 
			System.out.print(arr[i] + " "); 
		} 
	}
	
	public static void main(String[] args) {
		int[] nums = {1, 4, 3, 10, 9, 2, 6, 8, 7, 5}; 
		
		// �������� �� �迭 ��� 
		System.out.print("BEFORE: "); 
		printArr(nums);

		// ��������
		System.out.println("\nINSERTION SORT"); 
		insertionSort(nums);

		// �������� �� �迭 ��� 
		System.out.print("AFTER: "); 
		printArr(nums);
	}

}
