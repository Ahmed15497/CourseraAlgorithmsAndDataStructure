#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>



using std::endl;
using std::cout;

/*
long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    long long result = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
        	result = (long long) numbers[first] * numbers[second];
            max_product = std::max(max_product, result);
            
        }
    }

    return max_product;
}

*/



long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    long long result = 0;
    int max_first_index = -1;
    int max_second_index = -1;
    int max_number_temp = -1;
    int n = numbers.size();
    
    // find index of the max number
    for(int i = 0; i < n; ++i){
    	if (numbers[i] > max_number_temp){
    		max_first_index = i;
    		max_number_temp = numbers[i];
		}
	}
    // find index of the second max number
    max_number_temp = -1;
    for(int i =0; i<n; ++i){
    	if(i == max_first_index){
    		continue;
		}
		if(numbers[i] > max_number_temp){
    		max_second_index = i;
    		max_number_temp = numbers[i];			
		}
		
	}
    // multiply them
	max_product = (long long) numbers[max_first_index] * numbers[max_second_index];
    return max_product;
}


int main() {
	/*
	clock_t start, end;
	double msecs;

    start = clock();
	*/
	
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers)<< "\n";
    /*
    end = clock();
	msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;

    
	std::cout << msecs<< "\n";
	*/

	

    return 0;
}
