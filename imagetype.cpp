#include "imagetype.h"

QString imageTypeToString(ImageType imageType) {
    switch(imageType){
        case ImageType::PNG: return "PNG";
        case ImageType::JPG: return "JPG";
    }
}
