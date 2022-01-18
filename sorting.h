#ifndef SORTING_H
#define SORTING_H

#endif // SORTING_H

#include <QString>

enum Sorting{
    AZProd = 1,
    ZAProd = 2,
    AZModel = 3,
    ZAModel = 4,
    PriceAsc = 5,
    PriceDsc = 6
};
QString sortingToString(Sorting sorting);
Sorting stringToSorting(QString sorting);
QString sortingToSQL(Sorting sorting);
