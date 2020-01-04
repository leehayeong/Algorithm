/*  
 * SelectionSort.java 
 * Selection Sort Example 
 * Lee Ha Yeong  
 * 2019.09.01 
 */ 

public class SelectionSort { 

	public static void main(String[] args) { 
		int[] num = {1, 4, 3, 10, 9, 2, 6, 8, 7, 5}; 
		int min, index, tmp; 

		// 선택정렬 전 배열 출력 
		System.out.print("BEFORE: "); 
		for(int i = 0; i < num.length; i++) { 
			System.out.print(num[i] + " "); 
		} 

		// 선택정렬 
		System.out.println("\nSELECTION SORT"); 
		for(int i = 0; i < num.length; i++) { 
			min = num[i]; 
			index = i; 

			for(int j = i; j < num.length; j++) { 
				if(num[j] < min) { 
					min = num[j]; 
					index = j; 
				} 
			} 

			tmp = num[i]; 
			num[i] = num[index]; 
			num[index] = tmp; 
		} 

		// 선택정렬 후 배열 출력 
		System.out.print("AFTER: "); 
		for(int i = 0; i < num.length; i++) { 
			System.out.print(num[i] + " "); 
		} 
	} 

} 