class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1){
            return '0';
        }

        int mid = pow(2,n-1);

        if(k < mid){
            return findKthBit(n-1, k);
        } else if (k==mid){
            return '1';
        }
        else{
            if (findKthBit(n-1, mid*2-k) == '1'){
                return '0';
            }
            else{
                return '1';
            }
        }
        return 'N';
    }
    
};