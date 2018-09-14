/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 14 September, 2018, 4:25 PM
 */

#include <cstdlib>
#include <array>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 
 */

template<typename ForwardIter>
bool is_palindrome_permutation(ForwardIter begin, ForwardIter end)
{
    using value_type = typename std::iterator_traits<ForwardIter>::value_type;
    std::unordered_map<value_type, size_t> m;

    while (begin != end && *begin) // *begin: a dirty hack for correctness
    {                              // on zero-terminated C strings.
        m[*begin]++;
        ++begin;
    }

    size_t count = 0;

    for (auto& pair : m)
    {
        if (pair.second % 2 == 1)
        {
            if (++count == 2)
            {
                return false;
            }
        }
    }

    return true;
}

template<typename Sequence>
bool is_palindrome_permutation(const Sequence& seq)
{
    return is_palindrome_permutation(std::begin(seq), std::end(seq));
}

int main(int argc, char** argv) {
    char str[] = "tacocat";
    cout << "string:"<<str<<endl;
    cout << "Palindrome permutation: "
         << std::boolalpha
         << is_palindrome_permutation(str,
                                      str + sizeof(str) / sizeof(str[0]))
         << endl;
    
   
    std::string str2{"atcocta"};
    cout << "string:"<<str2<<endl;
    cout << "Palindrome permutation: "
         << is_palindrome_permutation(str2)
         << endl;

    std::vector<char> vec;
    std::copy(str2.begin(), str2.end(), std::back_inserter(vec));
    cout << "Palindrome permutation: "
         << is_palindrome_permutation(vec)
         << endl;
    return 0;
}
