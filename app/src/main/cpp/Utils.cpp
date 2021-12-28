//
// Created by Administrator on 2021/12/28.
//

#include "Utils.h"

/**
 * 获取 assets 目录下的文件内容
 * @param aAssetManager asset资源管理器
 * @param path 文件路径
 * @param fileSize 接收文件大小
 * @return 文件内容
 */
unsigned char *LoadFileContent(AAssetManager *aAssetManager, const char *path, int &fileSize) {
    //用来保存文件内容
    unsigned char *fileContent = nullptr;
    //表示文件大小，读取前为空
    fileSize = 0;
    //AAsset 表示一个 asset 目录下的文件，这里根据目录去打开一个文件
    AAsset *aAsset = AAssetManager_open(aAssetManager, path, AASSET_MODE_UNKNOWN);
    if (aAsset != nullptr) {
        //如果文件不为空，说明获取成功了，开始读取
        fileSize = AAsset_getLength(aAsset);
        //为什么加一？因为要在文件尾部写入\0的标记，表示结尾
        fileContent = new unsigned char[fileSize + 1];
        AAsset_read(aAsset, fileContent, fileSize);
        fileContent[fileSize] = 0;
        AAsset_close(aAsset);
    }
    return fileContent;
}
