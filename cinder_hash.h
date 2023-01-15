//
// Created by Rufelle on 13/01/2023.
//

#ifndef CINDER_CINDER_HASH_H
#define CINDER_CINDER_HASH_H
#include <functional>
#include <iostream>
//#define function(x, y, z) std::function<y(z)> x = [&](z params)
#define __ver__ 0.2

//#define function1(x, y, z) std::function<y(z)> x = [&]
#define function(x, y, ...) std::function<y(__VA_ARGS__)> x = [&]


#endif //CINDER_CINDER_HASH_H
