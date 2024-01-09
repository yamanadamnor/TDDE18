#include <vector>
#include <iostream>

/*

Expected output:

1970-01-01
Thursday 1/1/1970
2000-12-24
Christmas Eve 12/24/2000
2020-02-19
Thursday 2/19/2020

*/
int main()
{
    std::vector</* Date */> dates = {
        YMD_Date{1970, 1, 1},
        MDY_Date{"Thursday", 1970, 1, 1},
        YMD_Date{2020, 2, 19},
        MDY_Date{"Thursday", 2020, 2, 19}
    };

    for (/* Date */ date : dates)
    {
        std::cout << /* date.to_string() */ << std::endl;
    }
}
