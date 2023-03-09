//Sort 0s,1s and 2s
/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0 , one = 0, two = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)
             zero++;
            else if(nums[i] == 1)
            one++;
            else if(nums[i] == 2)
            two++;
        }
        for(int i = 0; i < zero; i++){
            nums[i] = 0;
        }
        for(int i = zero; i < zero+one; i++){
            nums[i] = 1;
        }
        for(int i = zero+one; i < nums.size(); i++){
            nums[i] = 2;
        }
    }
};


*/
//Move all negative elements to end
/*
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
       int arr1[n];
       int last = 0;
       for(int i = 0; i < n ; i++){
           if(arr[i] >= 0){
               arr1[last] = arr[i];
               last++;
           }
       }
       for(int i = 0 ; i < n; i++){
           if(arr[i] < 0){
               arr1[last] = arr[i];
               last ++;
           }
       }
       for(int i = 0; i < n; i++){
           arr[i] = arr1[i];
       }
    }
};
*/


//Union of two arrays
/*
class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set <int> st;
        for(int i = 0; i < n; i++){
            st.insert(a[i]);
        }
        for(int i = 0; i < m; i++){
            st.insert(b[i]);
        }
        return st.size();
    }
};
*/


//intersection of two arrayes
/*
//fastest solution
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int intersection1[1000] ={0} ;
        int intersection2[1000] ={0} ;
        vector <int> ans;
        for(int i = 0; i < nums1.size(); i++){
            intersection1[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size(); i++){
            intersection2[nums2[i]]++;
        }
        for(int i = 0; i < 1000; i++){
            if(intersection1[i] >= 1 && intersection2[i] >=1 ){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
//using maps
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums1.size(); i++){
            mp[nums1[i]] = 1;
        }
        vector <int> ans;
        for(int i = 0;i < nums2.size(); i++ ){
            if(mp[nums2[i]] == 1){
                ans.push_back(nums2[i]);
                mp[nums2[i]] = 0;
            }
        } 
        return ans;
    }
};
*/

//maximum sum contigious subarray
/*
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        int maxSum = arr[0];
        int currSum = arr[0];
        for(int i = 1; i < n; i++){
            currSum = max(arr[i], currSum + arr[i]);
            maxSum =  max(maxSum, currSum);
        }
        return maxSum;
    }
};
*/


//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
//not able to solve try again



//good logic
//find the repeating number / duplicate
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0] != nums[nums[0]]){
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};
*/
//using tortise and hare method
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast );
        fast = nums[0];
        while(fast != slow ){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
*/


//merge two arrays using o(1) space
//insertion sort concept(a little slow)
/*
class Solution {
private:
    void insertionSort(long long arr2[], int m) {
        for (int i = 1; i < m; i++) {
            long long key = arr2[i];
            int j = i - 1;
            while (j >= 0 && arr2[j] > key) {
                arr2[j + 1] = arr2[j];
                j--;
            }
            arr2[j + 1] = key;
        }
    }
    
public:
    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m) { 
        for (int i = 0; i < n; i++) {
            if (arr1[i] > arr2[0]) {
                swap(arr1[i], arr2[0]);
                insertionSort(arr2, m);
            }
        }
    } 
};

*/

//merge intervals


// permutations of a array and a string

//count inversion

//best time to buy and sell
//kandane's algo
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
    int current_profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        int diff = prices[i] - prices[i-1];
        current_profit = max(0, current_profit + diff);
        max_profit = max(max_profit, current_profit);
    }
    return max_profit;
    }
};
*/

//find all the pairs with sum = k
/*
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i = 0; i < n ; i++){
            int value = k - arr[i];
            if(mp[value]){
               ans = ans + mp[value];
            }
               mp[arr[i]]++; 
        }
       return ans;
    }
};

*/



//common elements in three arrays
/*
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            unordered_map<int,int>map;
            for(int i = 0; i < n1; i ++){
                map[A[i]] = 1;          //to avoid adding frequencies after wwe know its there
            }
            for(int i = 0; i < n2; i++){
                if(map[B[i]] != 0){
                    map[B[i]] = 2;
                }
            }
            vector<int>alpha;
            for(int i = 0; i < n3; i++){
                if(map[C[i]] > 1){
                    alpha.push_back(C[i]);
                    map[C[i]] = 0;      //essential step to avoid repeatative adding number in the vector
                }
            }
            return alpha;
        }

};
*/


//rearrange array in alternating positions




//find the subarray with sum zero
//v.v.v.v.v.v.v goood
/*class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> s;
        int pre_sum = 0;
        for (int i = 0; i < n; i++){
            pre_sum += arr[i];
            
            if(pre_sum == 0){
                return true;
            }
            if(s.find(pre_sum) != s.end()){
                return true;
            }
            s.insert(pre_sum);
        }
        return false;
    }
};
*/


//find factorial of a large number



//maxium product subarray


//longest consective subarray
/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>hashSet;
        for(int num : nums){
            hashSet.insert(num);
        }
        int streak;
        for(int num : nums){
            if(!hashSet.count(num-1)){
                int currNumber = num;
                int currStreak = 1;
                while(hashSet.count(currNumber+1)){
                    currNumber += 1;
                    currStreak += 1;
                }
                streak = max(streak, currStreak);
            }
        }
        return streak;
    }
};
*/



//Count More than n/k Occurences
/*
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        int rep = n/k;
        unordered_map<int,int> freq;

        for(int i = 0; i < n; i++){
            freq[arr[i]]++;
        }
        //now we find the numbers using the count
        unordered_map<int,int> :: iterator it = freq.begin();
        int count = 0;
        while(it != freq.end()){
            if(it->second > rep){
                count++;
            }
            it++;
        }
         return count;
    }
   
};
*/


//gooooooood   question
//maximum profit by buying and selling the stock in two days atmost
/*
int maxProfit(vector<int>&price){
    int n = price.size();
    int arr1[n] = {0};
    int maxElement = price[n-1];
    
    for(int i = n-2; i >= 0; i--){
    if(price[i] > maxElement)
        maxElement = price[i];
        
        arr1[i] = max(arr1[i+1], maxElement - price[i]);
    }
    int minElement = price[0];
    for(int i = 1; i < n; i++){
        if(price[i] < minElement)
            minElement = price[i];
        
        arr1[i] = max(arr1[i-1], arr1[i]+ (price[i] - minElement));
    }
    int result = arr1[n-1];
    return result;
}
*/


//find whether the array is a subset of another array
//hint= if two elements are similar in the smaller array then problem hogi thats why i check in the map in the end
/*
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> mp;
    for(int i = 0; i < m ; i++){
        mp[a2[i]] ++;
    }
    for(int i = 0; i < n ; i++){
        if(mp.find(a1[i]) != mp.end()){
            mp[a1[i]] --;
        }
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second > 0){
            return "No";
        }
    }
    return "Yes";
*/


//triple sum in an array t(O(n)^2)
//brute force use 3 loops. But we sorted it first then used left right approach.
/*
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A, A + n );
        for(int i = 0; i < n - 2; i++){
            
            int left = i + 1;
            int right = n - 1;
            
            while(right > left){
                int sum = A[i] + A[right] + A[left];
                if(sum > X){
                    right--;
                }
                if(X == sum){
                    return true;
                }
                if(X > sum ){
                    left++;
                }
            }
        }
        return false;
    }

};
*/


//imp
//trapping rainwater problem
/*
//here we dont store on the first and last tower as they cant store
class Solution {
public:
    int trap(vector<int>& height) {
        //to find the left max for a perticular height
        int n = height.size();
        vector<int> arrLeft(n);
        vector<int> arrRight(n);
        arrLeft[0] = height[0];
        for(int i = 1; i < n; i++){
            arrLeft[i] = max(arrLeft[i-1], height[i]);
        }
        arrRight[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            arrRight[i] = max(arrRight[i+1],height[i]);
        }
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            ans = ans + min(arrRight[i], arrLeft[i]) - height[i];
        }
        return ans;
    }
};
*/


//Chocolate distribution problem
//we had to sort the problem first then look for the subarray with min required condn
/*
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
       sort(a.begin() , a.end());
       long long ourMin = INT_MAX;
       for(int i = 0; i < n - m + 1 ; i++){
           ourMin = min(ourMin, a[i+m-1] - a[i]);
       }
       return ourMin;
    }   
};
*/


//min subarray with sum greater than or equal to the number
//first we will iterate to the point where out initail subarray hits the target or is more than the
//target we will get our first window. then we will be shrinking out window basically from the
//left side, here we will be storing the minimum window possible. we will repeat the process till we reacch the end of the array.
/*
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int result = INT_MAX;
        int val_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            val_sum += nums[i];
            while(val_sum >= target){
                result = min(result, i+1-left);
                val_sum -= nums[left];
                left++;
            }
        }
        return (result != INT_MAX ) ? result : 0;
    }
};
*/


//minimum swaps to bring k elements together
/*
class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int good = 0;
        //finding the good elements for my window size
        for(int i = 0; i < n; i++){
            if(arr[i] <= k){
                good++;
            }
        }
        //creaating a window 
        
        int bad = 0;
        //counting bad elements in the good window
        for(int i = 0; i < good; i++){
            if(arr[i] > k ){
                bad++;
            }
        }
        //moving the window 
        
        int s = 0; 
        int j = good; int ans = bad ;
        while(j < n){
            if(arr[s] > k)
            bad--;
            
            if(arr[s] > k)
            bad++;
            
            s++,j++;
            ans = min(bad , ans);
        }
        return ans;
        
    }
};
*/


//check if the number is pallindrom    
//good for checking the last number
/*
class Solution {
private:
    bool Pallindrome(int num){
        //first number 
        int digit, revNum = 0 ;
        int orignalNum = num;
        while(num > 0){
            digit = num % 10;
            revNum = revNum*10 + digit;
            num = num /10;
        }
        if(revNum == orignalNum ){
            return true;
        }
        else{
            return false;
        }
        
        git@github.com:owais0017/solutions-DSA.git
    }
public:
    int PalinArray(int a[], int n)
    {
        for(int i = 0; i < n; i++){
            bool ans = Pallindrome(a[i]);
            if(ans == false){
                return false;
            }
        }
        return true;
    }
};
*/