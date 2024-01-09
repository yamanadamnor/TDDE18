#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

/*

  Expected output:

07:00-08:00 Eat breakfast
08:00-10:00 Go to morning lecture
10:00-12:00 Study
12:00-13:00 Eat lunch
13:00-15:00 Afternoon lecture
15:00-17:00 Lab work
17:00-18:00 Go Home
18:00-19:00 Eat dinner
18:00-22:00 Relax
22:00-07:00 Sleep
  
 */

int main()
{
    std::vector<std::string> first_schedule = {
        "17:00-18:00 Go Home",
        "08:00-10:00 Go to morning lecture",
        "15:00-17:00 Lab work",
        "10:00-12:00 Study",
        "13:00-15:00 Afternoon lecture",
        "18:00-22:00 Relax"
    };

    std::vector<std::string> second_schedule {
        "07:00-08:00 Eat breakfast",
        "18:00-22:00 Relax",
        "18:00-19:00 Eat dinner",
        "12:00-13:00 Eat lunch",
        "22:00-07:00 Sleep"
    };

    std::sort(first_schedule.begin(), first_schedule.end());
    std::sort(second_schedule.begin(), second_schedule.end());

    std::cout << std::endl;


    std::vector<std::string> combined_schedule{};
    std::copy(first_schedule.begin(), first_schedule.end(), combined_schedule.begin());

    for(const auto &el : combined_schedule) {
        std::cout <<  el << std::endl;
    };

    
    // 3. Copy first_schedule and second_schedule into
    //    combined_schedule in such a way that the events are sorted.

    // 4. Remove any duplicates from combined_schedule.

    // 5. Print each event in combined_schedule, one line per event.
}
