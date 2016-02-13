//
//  main.cpp
//  Hello
//
//  Created by Jun Chen on 16/2/13.
//  Copyright © 2016年 Jun Chen. All rights reserved.
//

#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello, World! from work thread\n";
}

int main(int argc, const char * argv[]) {
    std::thread t(hello);
    t.join();
    std::cout << "Main Thread" << std::endl;
               
    return 0;
}
