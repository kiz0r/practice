/**
@file num_to_str.c
@author Хоменко К., гр. 515-в
@date 21 серпня 2022р.
@brief Навчальна практика.
*/

#include "num_so_str.h"

sds GetNumberName(int number)
{
    sds result = sdsempty();

    //додавання мінуса, якщо число відʼємне, та перетворення числа на додатнє
    if (number < 0)
    {
        result = sdscat(result, "мінус ");
        number = -number;
    }

    for (int i = 0; i < length; i++)
    {
        int number = numbers[i].value;

        if (number == number)
            return numbers[i].name;
    }

    if (number < 100)
    {
        result = sdscat(result, GetNumberName(number / 10 * 10));
        result = sdscat(result, " ");
        result = sdscat(result, GetNumberName(number % 10));
    }
    else if (number < 1000)
    {
        result = sdscat(result, GetNumberName(number / 100 * 100));
        result = sdscat(result, " ");
        result = sdscat(result, GetNumberName(number % 100));
    }
    else if (number < 1000000)
    {
        sds placeName = sdsempty();

        if ((number / 1000) % 10 == 1)
        {
            if ((number / 10000) * 10 != 0)
            {
                result = sdscat(result, GetNumberName((number / 10000) * 10));
                result = sdscat(result, " ");
            }
            result = sdscat(result, "одна тисяча ");
            result = sdscat(result, GetNumberName(number % 1000));
        }
        else if ((number / 1000) % 10 == 2)
        {
            if ((number / 10000) * 10 != 0)
            {
                result = sdscat(result, GetNumberName((number / 10000) * 10));
                result = sdscat(result, " ");
            }

            result = sdscat(result, "дві тисячі ");
            result = sdscat(result, GetNumberName(number % 1000));
        }
        else
        {
            placeName = (number / 1000) % 10 == 0 ? "тисяч " : (number / 1000) % 10 <= 4 ? "тисячі "
                                                                                         : "тисяч ";
            result = sdscat(result, GetNumberName(number / 1000));
            result = sdscat(result, " ");
            result = sdscat(result, placeName);
            result = sdscat(result, GetNumberName(number % 1000));
        };
    }
    else if (number < 1000000000)
    {
        sds placeName = sdsempty();

        if ((number / 1000000) % 10 == 1)
            placeName = sdscat(placeName, "мільйон");
        else if ((number / 1000000) % 10 <= 4)
            placeName = sdscat(placeName, "мільйони");
        else
            placeName = sdscat(placeName, "мільйонів");

        result = sdscat(result, GetNumberName(number / 1000000));
        result = sdscat(result, " ");
        result = sdscat(result, placeName);
        result = sdscat(result, " ");
        result = sdscat(result, GetNumberName(number % 1000000));
    }
    else
    {
        sds placeName = sdsempty();

        if ((number / 1000000000) % 10 == 1)
            placeName = sdscat(placeName, "мільʼярд");
        else
            placeName = sdscat(placeName, "мільʼярди");

        result = sdscat(result, GetNumberName(number / 1000000000));
        result = sdscat(result, " ");
        result = sdscat(result, placeName);
        result = sdscat(result, " ");
        result = sdscat(result, GetNumberName(number % 1000000000));
    }
    return result;
}
