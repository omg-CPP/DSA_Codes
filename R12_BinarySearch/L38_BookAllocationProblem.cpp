// GFG : Allocate Minimum Pages

// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.

// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: If it is not possible to allocate books to all students, return -1.
// if no of students > no of books , ans = -1

// eg : arr[] = {25,46,28,49,24}
// students = k = 4

// possible allocations : 
// 1 :: 25 | 46 | 28 | 49 24 :: max = 73
// 2 :: 25 | 46 | 28 49 | 24 :: max = 77
// 3 :: 25 | 46 28 | 49 | 24 :: max = 74
// 4 :: 25 46 | 28 | 49 | 24 :: max = 71

// so the ans = 71 (minimum)

// Example :
// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// => [12] and [34, 67, 90] Maximum Pages = 191
// => [12, 34] and [67, 90] Maximum Pages = 157
// => [12, 34, 67] and [90] Maximum Pages = 113.
// The third combination has the minimum pages assigned to a student which is 113.

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

// We need to allocate all books to the students

// lower range of binary search
// We started with 49 so that each student could get atleast a single book, if we would have taken 24 instead than books 25, 46, 28 and 49 have not gone to anyone.

// We would do this process till sum of all pages of books, why because if there is only one student, than all books would be given to him only.

int findMax(vector<int>& books) {
    int n = books.size();
    int maxElement = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        maxElement = max(maxElement,books[i]);
    }
    return maxElement;
}

int summationOfArray(vector<int>& books) {
    int n = books.size();
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        sum += books[i];
    }
    return sum;
}

// maxPages : It's the maximum pages a student can hold
int countStudents(vector<int>& books, int maxPages) {
    int n = books.size();
    int students = 1;
    int pages = 0;
    for(int i = 0 ; i < n ; i++) {
        if(pages + books[i] <= maxPages) {
            // add pages to current student
            pages += books[i];
        }
        else {
            students += 1;
            // add pages to next student
            pages = books[i];
        }
    }
    return students;
}

// Linear Search :: Time Limit Exceeded
// T.C. = O((sum-max+1)*n)
// S.C. = O(1)
int findPagesBruteForce(vector<int>& books, int k) {
    int n = books.size();
    if(k > n) {
        return -1;
    }
    int ans = 0;
    int lo = *max_element(books.begin(),books.end());
    int hi = accumulate(books.begin(),books.end(),0);
    for(int i = lo ; i <= hi ; i++) {
        if(countStudents(books,i) <= k) {
            return i;
        }
    }
    return -1;
}

// Binary Search
// T.C. = O(log(sum-max+1)*n)
// S.C. = O(1)
int findPages(vector<int>& books, int k) {
    int n = books.size();
    if(k > n) {
        return -1;
    }
    // int lo = findMax(books);
    // int hi = summationOfArray(books);
    // Built-In C++ STL functions
    int lo = *max_element(books.begin(),books.end());
    int hi = accumulate(books.begin(),books.end(),0);
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        int students = countStudents(books,mid);
        // no ans will be available in this region
        if(students > k) { // we need exactly 4 students
            lo = mid+1;
        }
        else { // students <= k
            hi = mid-1;
        }
    }
    return lo;
}

int main()
{
    vector<int> books = {15,10,19,10,5,18,7};
    // vector<int> books = {25,46,28,49,24};
    int k = 5;
    cout<<findPagesBruteForce(books,k)<<endl; // -1
    cout<<findPages(books,k)<<endl; // 0
    return 0;
}

// books = {15,10,19,10,5,18,7}
// k = 5

// l = 19
// h = 84

// books = {15,10,19,10,5,18,7}
// possible allocations
// 15 | 10 | 19 | 10 | 5 18 7  :: max = 30 
// 15 | 10 | 19 | 10 5 18 | 7  :: max = 33
// 15 | 10 | 19 10 5 | 18 | 7  :: max = 34
// 15 | 10 19 10 | 5 | 18 | 7  :: max = 39
// 15 10 19 | 10 | 5 | 18 | 7  :: max = 44
// 15 | 10 | 19 | 10 5 | 18 7  :: max = 25
// 15 | 10 | 19 10 | 5 18 | 7  :: max = 29
// 15 | 10 19 | 10 5 | 18 | 7  :: max = 29
// 15 10 | 19 10 | 5 | 18 | 7  :: max = 25 :: ans :: minimum of all possible maximums
// many more cases are possible ----