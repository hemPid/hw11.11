#include <iostream>
#include <map>
#include <vector>
#include <queue>

using vec_type = std::vector<int>;
using ivec_type = std::vector<int>::iterator;
using map_type = std::map<int,int>;
using imap_type = std::map<int,int>::iterator;
using multimap_type = std::multimap<int, int>;
using imultimap_type = std::multimap<int, int>::iterator;

map_type get_frequency_map(vec_type & arr) {
    //returns map (element,frequency)
    map_type val_freq_map;
    for (ivec_type it = arr.begin(); it != arr.end(); it++)
    {
        if (val_freq_map.count(*it))
        {
            val_freq_map[*it] += 1;
        } else {
            val_freq_map.insert(std::make_pair(*it,1));
        }
    }
    return val_freq_map;
}

multimap_type get_sorted_frequences(map_type freq_map) {
    multimap_type res;
    for (imap_type it = freq_map.begin(); it != freq_map.end(); it++) {
        res.insert(std::pair<int,int>(it->second, it->first));
    }
    return res;
}

int get_more_than_half(vec_type & arr) {
    map_type freq_map = get_frequency_map(arr);
    multimap_type sorted_map = get_sorted_frequences(freq_map);
    imultimap_type last_el = sorted_map.end();
    last_el--;
    int len = arr.size();
    if (last_el->first > len/2)
    {
        return last_el->second;
    } else {
        //в задании не сказано, что делать в таком случае, пологаю, наличие такого элемента гарантируется
        return -1;
    }
}

vec_type get_more_than_third(vec_type & arr) {
    vec_type res;
    map_type freq_map = get_frequency_map(arr);
    multimap_type sorted_map = get_sorted_frequences(freq_map);
    imultimap_type last_el = sorted_map.end();
    last_el--;
    int len = arr.size();
    if (last_el->first > len/3)
    {
        res.push_back(last_el->second);
    } else {
        //в задании не сказано, что делать в таком случае, пологаю, наличие такого элемента гарантируется
        return res;
    }
    last_el--;
    if (last_el->first > len/3)
    {
        res.push_back(last_el->second);
    }
    return res;
}

vec_type get_first_k(vec_type & arr, int k) {
    vec_type res;
    map_type freq_map = get_frequency_map(arr);
    multimap_type sorted_map = get_sorted_frequences(freq_map);
    imultimap_type last_el = sorted_map.end();
    last_el--;
    for (int i = 0; i < k; last_el--, i++)
    {
        res.push_back(last_el->second);
    }
    return res;
}


int main() {
    vec_type m = {1,1,2,2,2,3,3,3,3,3, 4};
    //std::cout << get_more_than_half(m) << std::endl;
    vec_type res = get_first_k(m, 4);
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}