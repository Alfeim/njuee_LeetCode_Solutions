/********************************************
作者:Alfeim
题目:拼接最大数
时间消耗:28ms
解题思路:对于从一个数组中选取N个元素拼接成最大数的
问题比较直观:利用贪心算法,依次遍历数组,如果当前元素
大于栈顶元素,则不断出栈,直到栈中元素个数与后续数组元素
个数之和不再大于N 或者 栈顶元素大于当前元素为为止,
然后将当前元素入栈;

如果把问题扩展到两个数组,我们可以从第一个数组抽取
i个,第二个数组抽取N-i个元素,这样就可以把问题转换为
两个数组分别寻找最大数,找到后,将两个临时数组合并.
因为无法确定i取多少是最好的,所以我们要对i进行遍历;
********************************************/
class Solution {
public:

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(),n = nums2.size();
        vector<int> ans(k);
        for(int i = max(0,k-n) ; i <= m && i <= k ; ++i){
            vector<int> tmp1 = MaxNumber(nums1,i);
            vector<int> tmp2 = MaxNumber(nums2,k-i);
            vector<int> Candidate = Merge(tmp1,tmp2,k);
            if(compare(Candidate,0,ans,0)) ans = Candidate;
        }
        return ans;
    }

    vector<int> MaxNumber(vector<int> &nums,int size){
        int n = nums.size();
        vector<int> tmp(size);
        for(int i = 0,j = 0 ; i < n;++i){
            while(j > 0 && n - i + j > size &&  tmp[j - 1] < nums[i]) j--;
            if(j < size) tmp[j++] = nums[i];
        }
        return tmp;
    }

    bool compare(vector<int> &nums1,int pos1,vector<int> &nums2,int pos2){
        while(pos1 < nums1.size() && pos2 < nums2.size()){
            if(nums1[pos1] == nums2[pos2]){
                pos1++;
                pos2++;
                continue;
            }else{
                if(nums1[pos1] > nums2[pos2])
                    return true;
                return false;
            }
        }
        return pos2 == nums2.size();
    }

    vector<int> Merge(vector<int> &nums1,vector<int> &nums2,int k){
        vector<int> res(k);
        int pos1 = 0,pos2 = 0;
        for(int i = 0 ; i < k ;++i){
            if(compare(nums1,pos1,nums2,pos2)) 
                res[i] = nums1[pos1++];
            else
                res[i] = nums2[pos2++];
        }
        return res;
    }

};
