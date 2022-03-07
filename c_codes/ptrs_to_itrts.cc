#include<stdio.h>

int sum1(int a[], int size){
    int sum = 0;
    for(int i=0; i!=size; ++i){
        sum += a[i];
    }
    return sum;
}

int sum2(int *first, int *last){
    int sum = 0;
    while(first != last){
        sum += *first;
        ++first;
    }
    return sum;
}


int main(){
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s1 = sum1(a, 10);       // 45
    int s2 = sum1(&a[0], 10);   // same as s1
    int s3 = sum1(&a[1], 5);    // sums s[1]...s[5], computing 15
    int s4 = sum1(a + 1, 5);    // same as s3
    printf("%d\n", s3);

    int s5 = sum2(a, a + 10);
    int s6 = sum2(&a[0], &a[0] + 10);
    int s7 = sum2(&a[1], &a[1] + 5);
    int s8 = sum2(a + 1, a + 6);
    printf("%d\n", s8);
    return 0;
}


//Note that the data from first to last forms a half-open range. iIn mathematical notation, we care about elements in the range [first, last): the element pointed to by first is included (if it exists), but the element pointed to by last is not.

//So in C, two pointers naturally express a range of an array. The C++ standard template library, or STL, brilliantly abstracts this pointer notion to allow two iterators, which are pointer-like objects, to express a range of any standard data structure—an array, a vector, a hash table, a balanced tree, whatever. This version of sum works for any container of ints; notice how little it changed:

//template <typename It>
//int sum(It first, It last) {
    //int sum = 0;
    //while (first != last) {
        //sum += *first;
        //++first;
    //}
    //return sum;
//}

// Some example use cases:
//std::set<int> set_of_ints;
//int s1 = sum(set_of_ints.begin(), set_of_ints.end());
//std::list<int> linked_list_of_ints;
//int s2 = sum(linked_list_of_ints.begin(), linked_list_of_ints.end());
