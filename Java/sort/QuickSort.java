  
/*  
 * QuickSort.java 
 * Lee Ha Yeong  
 * 2019.09.24
 */ 

public class QuickSort {
	public static void quickSort(int[] nums, int start, int end) {
		if(start >= end) {	// 원소가 1개인 경우 
			return;
		}
		
		int pivot = start;	// 피벗값은 첫번째 원소
		int i = start + 1;	// 왼쪽 출발지-오른쪽으로 진행하며 피벗보다 큰 값을 찾기 위한 인덱스
		int j = end;		// 오른쪽 출발지-왼쪽으로 진행하며 피벗보다 작은 값을 찾기 위한 인덱스
		int tmp;
		
		while (i <= j) {	// 엇갈리지 않을 때까지 반복
			while(nums[i] <= nums[pivot] && i <= end) {	// 피벗보다 큰 값을 만날때까지 오른쪽으로 이동
				i++;
			}
			while(nums[j] >= nums[pivot] && j > start) {	// 피벗보다 작은 값을 만날때까지 왼쪽으로 이동
				j--;
			}
			if(i > j) {	// 엇갈린 상태면 j,피벗 해당 값 교체
				tmp = nums[j];
				nums[j] = nums[pivot];
				nums[pivot] = tmp;
			} else { // 엇갈리지 않았다면 i,j 해당 값 교체
				tmp = nums[j];
				nums[j] = nums[i];
				nums[i] = tmp;
			}
		}
		
		// 데이터가 엇갈려서 빠져나온 상태
		// j와 피벗이 교체됐으므로 j가 피벗이 있는 위치
		// 피벗 기준으로 왼쪽, 오른쪽으로 각각 퀵정렬을 시행
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
		
		// 퀵정렬 전 배열 출력 
		System.out.print("BEFORE: "); 
		printArr(nums);

		// 퀵정렬
		System.out.println("\nQUICK SORT"); 
		quickSort(nums, 0, nums.length-1);

		// 퀵정렬 후 배열 출력 
		System.out.print("AFTER: "); 
		printArr(nums);
	}

}
