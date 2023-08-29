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


  // node : fre, char , left child
  using value = std::tuple<int,char>;
  auto [fre,ch] = value a{1,'a'};
  using node = std::tuple<value ,value*,value*>;
  std::unique_ptr<node> root = std::make_unique<node>(std::make_tuple(0,' '), nullptr, nullptr);

  struct xx {
    int i;
    xx* left;
    xx* right;
  };
  
node_generate:
  int node_num = 0;
  for (auto element : _ ) {
    if (node_num == 2) {
      goto node_generate;
    }
    std::cout << element.first << element.second << std::endl;

    node_num++;
  }



};

}

#endif //HUFFMAN_CODING_DEMO_HUFFMAN_CODING_TEST1_BASE_CODING_H_
