class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size()<3) return 0;

        int max_index(0);
        for(int i=1 ;i<height.size();i++){
            if(height[max_index] < height[i] ) max_index = i;
        }

        int i(0),j(1), res(0);

        while(j < max_index ){
            while(height[j]<height[i]) j++;
            int area = (j-i-1)*height[i];
            i++;
            while(i<j){
                area -= height[i];
                i++;
            }
            //cout << "area added :" << area << " i : " << i << " j : " << j << endl;
            res += area;
            j++;
        }

        i = height.size()-1;
        j = height.size()-2;

        while(j> max_index){
            while(height[i] > height[j]) j--;
            int area = (i-j-1)*height[i];
            i--;
            while(i > j) {
                area -= height[i];
                i--;
            }
            //cout << "area added :" << area << " i : " << i << " j : " << j << endl;
            res += area;
            j--;
        }
        return res;
    }
};