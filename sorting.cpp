#include "sorting.h"


QString sortingToString(Sorting sorting)
{
    switch(sorting){
    case AZProd:
        return "A-Z producer";
        break;
    case ZAProd:
        return "Z-A producer";
        break;
    case AZModel:
        return "A-Z model";
        break;
    case ZAModel:
        return "Z-A model";
        break;
    case PriceAsc:
        return "Price ascending";
        break;
    case PriceDsc:
        return "Price descending";
        break;

    }
}

Sorting stringToSorting(QString sorting)
{
    sorting = sorting.toUpper();
    if(sorting == "A-Z PRODUCER") return Sorting::AZProd;
    else if(sorting == "Z-A PRODUCER") return Sorting::ZAProd;
    else if(sorting == "A-Z MODEL") return Sorting::AZModel;
    else if(sorting == "Z-A MODEL") return Sorting::ZAModel;
    else if(sorting == "PRICE ASCENDING") return Sorting::PriceAsc;
    else if(sorting == "PRICE DESCENDING") return Sorting::PriceDsc;
    else return Sorting::AZProd;
}

QString sortingToSQL(Sorting sorting)
{
    switch(sorting){
    case AZProd:
        return "producer ASC";
        break;
    case ZAProd:
        return "producer DESC";
        break;
    case AZModel:
        return "model ASC";
        break;
    case ZAModel:
        return "model DESC";
        break;
    case PriceAsc:
        return "price ASC";
        break;
    case PriceDsc:
        return "price DESC";
        break;

    }
}
