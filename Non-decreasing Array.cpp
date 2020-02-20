bool checkPossibility(vector<int>& nums) {
        int count = 0;

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(nums.size() <= 1)
            return true;
        if(nums[0] > nums[1]){
            count++;
            nums[0] = nums[1];
        }
        for(int i = 2; i < nums.size(); i++){
            if(nums[i - 2] > nums[i]){
                count++;
                nums[i] = nums[i - 2];
            }
            else if(nums[i - 1] > nums[i]){
                count++;
                nums[i - 1] = nums[i];
            }
        }
        if(count > 1)
            return false;
        return true;
    }
};
