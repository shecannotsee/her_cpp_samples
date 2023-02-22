//
// Created by shecannotsee on 2023/2/22.
//

#ifndef BUFFER_DESIGN_TEST_BUFFER_DESIGN_TEST_FOR_REFERENCE_ONLY_H_
#define BUFFER_DESIGN_TEST_BUFFER_DESIGN_TEST_FOR_REFERENCE_ONLY_H_

#include <string>
#include <vector>

namespace {

std::vector<std::string,std::string> xxx = {
    "0x01 = 0000 0001",
    "0x02 = 0000 0010",
    "0x04 = 0000 0100",
    "0x08 = 0000 1000",
    "0x0C = 0000 1100",
    "0x0E = 0000 1110",
    "0x0F = 0000 1111",
    "0x07 = 0000 0111",
    "0x03 = 0000 0011",
    "0x0F & 0110 0110 -> 0000 0110",

    "END"
};// map xxx

};// namespace

#endif //BUFFER_DESIGN_TEST_BUFFER_DESIGN_TEST_FOR_REFERENCE_ONLY_H_
