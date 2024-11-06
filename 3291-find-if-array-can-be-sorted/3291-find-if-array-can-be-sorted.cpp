class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        bool trocou;
        int n = nums.size();
        map<int, int> mp;

        for(int i=0; i<n; i++) {
            int aux = nums[i];

            if(!mp[aux]) {
                while(aux) {
                    mp[nums[i]] += aux%2;
                    aux/=2;
                }
            }
        }
    
        for(int i=0; i<n-1; i++) {
            trocou = false;
            
            for(int j=0; j<n-i-1; j++) {
                if(nums[j] > nums[j + 1]) {
                    if(mp[nums[j]] != mp[nums[j+1]]) return false;

                    swap(nums[j], nums[j + 1]);
                    trocou = true;
                }
            }

            if (!trocou) break;
        }

        return true;
    }
};