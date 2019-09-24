  
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
			// 현재 위치에서 다음 원소와 비교. 
			// 이미 정렬되어있다면 앞 원소까지는 다 정렬되어 있는 것.
			while(nums[j] > nums[j+1]) {	
				tmp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = tmp;
				j--;	// 왼쪽으로 가며 위치 찾아가기 위한 비교
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
		
		// 삽입정렬 전 배열 출력 
		System.out.print("BEFORE: "); 
		printArr(nums);

		// 삽입정렬
		System.out.println("\nINSERTION SORT"); 
		insertionSort(nums);

		// 삽입정렬 후 배열 출력 
		System.out.print("AFTER: "); 
		printArr(nums);
	}

}
