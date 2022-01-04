#ifndef IMAGETYPE_H
#define IMAGETYPE_H
#include <QString>

enum ImageType {
    PNG = 1,
    JPG = 2
};

QString imageTypeToString(ImageType imageType);
#endif // IMAGETYPE_H
