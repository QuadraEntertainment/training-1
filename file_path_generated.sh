#!/bin/sh -e

CUR=$(pwd)
HEADER=${CUR}/Classes/FilePath_generated.h
RESOURCES=${CUR}/Resources
##
echo > ${HEADER}
echo "#ifndef __FILEPATH_GENERATED_H__" >> ${HEADER}
echo "#define __FILEPATH_GENERATED_H__" >> ${HEADER}
echo "" >> ${HEADER}
echo "#include \"cocos2d.h\"" >> ${HEADER}
echo "" >> ${HEADER}
echo "void addAllDirectoriesFilePath() {" >> ${HEADER}
echo "    cocos2d::FileUtils* fileutil = cocos2d::FileUtils::getInstance();" >> ${HEADER}
#echo "#ifdef ENABLE_DESIGN_DIRECTORY" >> ${HEADER}
#echo "    fileutil->addSearchPath(\"Publish/check\");" >> ${HEADER}
#echo "#endif" >> ${HEADER}

pushd ${RESOURCES}
DIRS=`find -L * -type d -print`
for dir in ${DIRS}
do
if [ `echo ${dir} | grep -v '.svn'  | grep -v 'Publish/check'` ] ; then
    echo "    fileutil->addSearchPath(\"${dir}\");" >> ${HEADER}
fi
done
popd # ${RESOURCES}

echo "}" >> ${HEADER}
echo "" >> ${HEADER}
echo "#endif  // __FILEPATH_GENERATED_H__" >> ${HEADER}
