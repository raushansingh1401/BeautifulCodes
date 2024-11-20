class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int sumGas(0), sumCost(0);

        for(int i = 0 ; i< gas.size() ; i++){
            sumGas += gas[i];
            sumCost += cost[i];
        }

        if(sumGas < sumCost) return -1;
        
        int curGas(0), ind(0);

        for(int i = 0 ; i < gas.size() ; i++){
            curGas += gas[i] - cost[i];
            if(curGas < 0){
                curGas = 0;
                ind = i + 1;
            }
        }

        return ind;
    }
};