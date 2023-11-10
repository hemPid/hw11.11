#include <iostream>
#include <vector>
#include <map>

using s_type = std::string;
using sv_type = std::vector<std::string>;
using isv_type = std::vector<std::string>::iterator;
using ssv_type = std::vector<std::vector<std::string>>;
using issv_type = ssv_type::iterator;
using symb_map_type = std::map<char, int>;
using isymb_map_type = std::map<char, int>::iterator;
using v_symb_map_type = std::vector<symb_map_type>;
using iv_symb_map_type = v_symb_map_type::iterator;



symb_map_type create_symb_map(s_type & word) {
    symb_map_type ret_val;
    for (char symb : word)
    {
        if (ret_val.count(symb))
        {
            ret_val[symb] += 1;
        } else {
            ret_val.insert(std::pair<char, int>(symb, 1));
        }
    }
    return ret_val;
}

bool comp_symb_maps(symb_map_type & a, symb_map_type & b) {
    if (a.size() != b.size())
    {
        return false;
    }
    for (isymb_map_type it = a.begin(); it != a.end(); ++it)
    {
        if (!b.count(it->first))
        {
            return false;
        }
        if (b[it->first] != a[it->first])
        {
            return false;
        }
    }
    return true;    
}


int is_map_defined(v_symb_map_type & arr, symb_map_type & val) {
    for (int i = 0; i != arr.size(); ++i)
    {
        if (comp_symb_maps(arr[i], val))
        {
            return i;
        }
    }
    return -1;
}


ssv_type groupByName(sv_type & strs) {
    v_symb_map_type sets;
    ssv_type ret_val;
    for (isv_type it = strs.begin(); it != strs.end(); ++it)
    {
        symb_map_type val;
        if (*it == "")
        {
            val.insert(std::pair<char, int>('\0',1));
        } else {
            val = create_symb_map(*it);
        }
        int idx = is_map_defined(sets, val);
        if (idx == -1)
        {
            sets.push_back(val);
            sv_type ins_val = {*it};
            ret_val.push_back(ins_val);
        } else {
            ret_val[idx].push_back(*it);
        }
    }
    return ret_val;
}

int main() {
    sv_type strs = {"eat","tea","tan","ate","nat","bat"};
    ssv_type res = groupByName(strs);
    for (issv_type it = res.begin(); it != res.end(); ++it)
    {
        for (isv_type it2 = it->begin(); it2 != it->end(); ++it2)
        {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}