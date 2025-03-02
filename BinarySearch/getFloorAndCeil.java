import java.util.* ;
import java.io.*; 

public class Solution {
    
    public static int[] getFloorAndCeil(int[] a, int n, int x) {
      int floor_index = -1, ceil_index = -1;
      int l = 0, h = a.length - 1;
	  
      while(l <= h){
        int mid = (l + h)/2;
		
        if(a[mid] == x){
          floor_index = mid;
          ceil_index = mid;
          break;
        }
        if(x < a[mid]){
          h = mid - 1;
          ceil_index = mid;
        }else {
          l = mid + 1;
          floor_index = mid;
        }
      }

      int floor = (floor_index == -1) ? -1 : a[floor_index];
      int ceil = (ceil_index == -1) ? -1 : a[ceil_index];

      return new int[]{floor, ceil};
    }
    
    
}