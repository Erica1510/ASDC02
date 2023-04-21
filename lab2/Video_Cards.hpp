//
//  Video_Cards.hpp
//  lab2
//
//  Created by Erica Diaciuc on 21.04.2023.
//

#ifndef Video_Cards_hpp
#define Video_Cards_hpp

#include <iostream>
#include <fstream>
#include <string>


class Video_Cards
{
public:
    int Product_code{0};
    std::string Name{""};
    std::string Producer{""};
    int TechnicalProcess{0};
    int EnergyConsum{0};
    float Price{0.0};
    
    void output(){
        std::cout << " " << Product_code << " " << Name << " " << Producer << " " << TechnicalProcess << " " << EnergyConsum << " " << Price;
    }
    
};


#endif /* Video_Cards_hpp */
