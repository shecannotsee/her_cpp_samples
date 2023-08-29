//
// Created by shecannotsee on 23-8-28.
//

#ifndef HUFFMAN_CODING_DEMO_HUFFMAN_CODING_TEST1_BASE_CODING_H_
#define HUFFMAN_CODING_DEMO_HUFFMAN_CODING_TEST1_BASE_CODING_H_

#include <string>
#include <tuple>
#include <unordered_map>
#include <map>
#include <memory>

namespace test1_base_coding {

void main() {
  std::string original_string = "helloworld";
  // aa->{a2}  abcc->{a1,b2,c2}  dsafsass->{a2,d1,f1,s4,}
  std::unordered_map<char ,int> char_table;/* fill data */ {
    for (const auto ch: original_string) {
      if (char_table.find(ch) != char_table.end()) {
        // Character is already in the map
        char_table[ch]++;
      } else {
        char_table.insert(std::make_pair(ch, 1));
      }
    }
  }

  // Sort characters by frequency of occurrence
  std::multimap<int,char/*,std::greater<int>*/> _;
  for(auto element : char_table) {
    std::cout << element.first << element.second << std::endl;
    _.insert(std::make_pair(element.second,element.first));
  }

  for(auto element : _) {
    std::cout << element.first << element.second << std::endl;
  }



};

}

#endif //HUFFMAN_CODING_DEMO_HUFFMAN_CODING_TEST1_BASE_CODING_H_
