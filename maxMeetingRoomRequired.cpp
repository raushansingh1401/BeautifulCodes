int Solution::solve(vector<vector<int> > &A) {
    
    vector<int> startIndVec, endIndVec;
    
    int maxNumRooms(INT_MIN), tempNumRooms(0);
    
    for(int i=0;i<A.size();i++){
        startIndVec.push_back(A[i][0]);
        endIndVec.push_back(A[i][1]);
    }
    
    sort(startIndVec.begin(), startIndVec.end());
    sort(endIndVec.begin(), endIndVec.end());
    
    int i(0),j(0);
    
    while(i<startIndVec.size() && j <endIndVec.size()){
        if(startIndVec[i]<endIndVec[j]){
            i++;
            tempNumRooms++;
        }else{
            j++;
            tempNumRooms--;
        } 
        maxNumRooms = max(maxNumRooms, tempNumRooms);
    }
    
    return maxNumRooms;
}