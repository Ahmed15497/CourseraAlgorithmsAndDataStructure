#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    int period = 0;
    std:: vector<int> series_mod = {0, 1};

    


    for (long long i = 2; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        //std::cout<<current<<std::endl;
        series_mod.push_back( current % m);
        std::cout << current % m << std::endl;
        if ((previous % m) == 0 && (current % m) == 1){
            period = i - 2;
            //std::cout<<"#####################################\n";
            //std::cout<<period<<std::endl;
            break;
        }
    }
    int index = n % period;


    return series_mod[index];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
