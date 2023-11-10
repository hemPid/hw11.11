#include <iostream>
#include <vector>
//O(n)
using vector_type = std::vector<int>;
using ivector_type = std::vector<int>::iterator;



void print_vect(vector_type & v) {
    for (ivector_type it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int removeDuplicates(vector_type & nums) {
    ivector_type comp_el = nums.begin();
    while (comp_el != nums.end())
    {
        ivector_type beg = comp_el + 1;
        if (*beg != *comp_el)
        {
            ++comp_el;
            continue;
        }
        ivector_type last = beg;
        for (;last != nums.end(); ++last)
        {
            if (*last != *comp_el)
            {
                break;
            }
        }
        nums.erase(beg, last);
        ++comp_el;
    }
    return nums.size();
}

int main() {
    vector_type test = {1,1,2,2,2,3,3,3,3,4,4,4,4,4,4};
    std::cout << removeDuplicates(test) << std::endl;
    print_vect(test);
    return 0;
}