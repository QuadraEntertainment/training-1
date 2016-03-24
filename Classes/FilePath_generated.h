
#ifndef __FILEPATH_GENERATED_H__
#define __FILEPATH_GENERATED_H__

#include "cocos2d.h"

void addAllDirectoriesFilePath() {
    cocos2d::FileUtils* fileutil = cocos2d::FileUtils::getInstance();
    fileutil->addSearchPath("fonts");
    fileutil->addSearchPath("res");
}

#endif  // __FILEPATH_GENERATED_H__
