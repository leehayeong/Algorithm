  
/*  
 * BubbleSort.java 
 * Lee Ha Yeong  
 * 2019.09.24
 */ 

public class BubbleSort {
	public static void bubbleSort(int[] nums) {
		int tmp;
		
		for(int i = 0; i < nums.length; i++) {
			for(int j = 0; j < nums.length-1-i; j++) {
				if(nums[j] > nums[j+1]) {
					tmp = nums[j];
					nums[j] = nums[j+1];
					nums[j+1] = tmp;
				}
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
		
		// 버블정렬 전 배열 출력 
		System.out.print("BEFORE: "); 
		printArr(nums);

		// 버블 정렬
		System.out.println("\nBUBBLE SORT"); 
		bubbleSort(nums);

		// 버블정렬 후 배열 출력 
		System.out.print("AFTER: "); 
		printArr(nums);
	}

}
