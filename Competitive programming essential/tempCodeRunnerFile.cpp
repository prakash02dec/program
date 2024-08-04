int max_length(vector<int> &rods , int idx , int tower1 , int tower2){
        int max_height {} ;
        max_height = tower1 == tower2 ? tower1 : 0 ;
        if(idx == rods.size()){
            return max_height;
        }
        
        int t1 {max_length(rods , idx + 1 , tower1+rods[idx] , tower2 )} ;
        int t2 {max_length(rods , idx + 1 , tower1 , tower2+rods[idx] )} ;
        int ex  {max_length(rods , idx + 1 , tower1 , tower2 )} ;
        return max({t1 , t2 , ex , max_height});
    }