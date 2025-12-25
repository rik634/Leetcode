// level: Medium
// problem statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
//Allocate books in such a way that:
// 1. Each student gets at least one book.
// 2. Each book should be allocated to only one student.
// 3. Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1
// brute force
class Solution{
int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int pages = low; pages <= high; pages++) {
        if (countStudents(arr, pages) == m) {
            return pages;
        }
    }
    return low;
}
// time complexity: O(n)+O(n*(sum-mx))
// space complexity: O(1)



// binary search
class Solution{
   public:
   int countPages(vector<int>& arr, int b){
      int count=0;
      int temp=0;
      for(int i=0;i<arr.size();i++){
         if((temp+arr[i)>b){
           count++;
           temp=arr[i];
         }
        else{
          temp+=arr[i];
        }
      }
     return count;
   }
   int findPages(vector<int>& arr, int m)
   {
       int n = arr.size();
       int mn = *max_element(arr.begin(),arr.end());
       int mx = accumulate(arr.begin(),arr.end(),0);
       int l=mn;
       int r=mx;
       int ans=-1;
       while(l<=r){
         int mid = (l+r)/2;
         int c = countPages(arr,mid);
         if(c<=m){
           ans=mid;
           r=mid-1;
         }
         else{
           l=mid+1;
         }
       }
     return ans;     
   }
};
// time complexity: O(n)+O(n*log(sum-mx))
// space complexity: O(1)
