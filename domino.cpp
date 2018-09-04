#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int solution(std::vector<int> &A, std::vector<int> &B) {
    
	int N = A.size();

	int ar[N][2];

	int variations;

    int j=0;
    for (std::vector<int>::iterator it = A.begin(); it != A.end(); it++)
        ar[j++][0] = *it;
    
    j=0;
    for (std::vector<int>::iterator it = B.begin(); it != B.end(); it++)
        ar[j++][1] = *it;
    
    // write your code in C++14 (g++ 6.2.0)
    std::qsort(ar, N, sizeof(*ar),
        [](const void *arg1, const void *arg2)->int
        {
            int const *lhs = static_cast<int const*>(arg1);
            int const *rhs = static_cast<int const*>(arg2);
            return (lhs[0] < rhs[0]) ? -1
                :  ((rhs[0] < lhs[0]) ? 1
                :  (lhs[1] < rhs[1] ? -1
                :  ((rhs[1] < lhs[1] ? 1 : 0))));
        });	  

	for (int i=0; i<N; i++){
		A[i] = ar[i][0];
		B[i] = ar[i][1]; 
	}

}

int main()
{

 	int ar[100][2];
    std::vector<int> Avec;
    std::vector<int> Bvec;

    // populate with random data
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::uniform_int_distribution<> dist(0,6);

    std::for_each(std::begin(ar), std::end(ar),
        [&](int (&ar)[2]){ ar[0] = dist(rng); ar[1] = dist(rng); });

	std::for_each(std::begin(ar), std::end(ar),
		[&](int (&ar)[2]){ Avec.push_back(ar[0]); Bvec.push_back(ar[1]); });      

    std::cout << "\nBefore sort..." << '\n';
    std::for_each(std::begin(ar), std::end(ar),
        [](const int(&ar)[2]) { std::cout << ar[0] << ',' << ar[1] << '\n';});

    solution(Avec, Bvec);

    int j=0;
    for (std::vector<int>::iterator it = Avec.begin(); it != Avec.end(); it++)
        ar[j++][0] = *it;

    j=0;
    for (std::vector<int>::iterator it = Bvec.begin(); it != Bvec.end(); it++)
        ar[j++][1] = *it;

    std::cout << "\nAfter sort..." << '\n';
    std::for_each(std::begin(ar), std::end(ar),
        [](const int(&ar)[2]) { std::cout << ar[0] << ',' << ar[1] << '\n';});

    return 0;
}