class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>p;
    int num;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            this->p.push(nums[i]);
            if(this->p.size()>k)
              this->p.pop();
        }
        num=k;
    }
    
    int add(int val) {
        this->p.push(val);
         if(this->p.size()>num)
              this->p.pop();
        return this->p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */