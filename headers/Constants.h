//
// Created by zenif on 12/09/2021.
//

#ifndef MAGE_CONSTANTS_H
#define MAGE_CONSTANTS_H

#include <map>

class Constants {
public:
    inline const static int gameHeight = 600; // pixels
    inline const static int gameWidth = 1000; // pixels

    inline const static int playerTag = 0;
    inline const static int foeTag = 1;
    inline const static int defaultTag = -1;

    inline const static std::map<int, std::map<int, bool>> collisionTable =
            {{playerTag, {{playerTag, false}, {foeTag, true}}},
             {foeTag,    {{playerTag, true},  {foeTag, false}}}};

    inline bool static mayCollide(int tag1, int tag2){
        return collisionTable.at(tag1).at(tag2);
    }
};

#endif //MAGE_CONSTANTS_H
