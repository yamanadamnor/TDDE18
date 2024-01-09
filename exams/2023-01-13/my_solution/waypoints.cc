#include<cmath>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<array>

int main() {
    std::ifstream ifs{ "WAYPOINTS.txt" };
    std::string coord;
    std::vector<std::pair<double, double>> coords;

    // Fill the container with coords
    std::for_each(std::istream_iterator<std::string>(ifs), std::istream_iterator<std::string>(),[&coords](const std::string line){
	// NOTE: Use stringstreams instead
        const auto split_at{line.find('-')};
        const double x_coord{std::stod(line.substr(0, split_at))};
        const double y_coord{std::stod(line.substr(split_at + 1, std::string::npos))};
        coords.push_back(std::pair<double, double>{x_coord, y_coord});
    });

    auto sum_points = [](const auto &a, const auto &b) {
        double x_diff{a.first - b.first};
        double y_diff{a.second - b.second};
        return std::sqrt(std::pow(x_diff, 2) + std::pow(y_diff, 2));
    };

    std::vector<double> dist;
    std::transform(std::next(coords.begin()), coords.end(), coords.begin(), std::back_inserter(dist), sum_points);
    double total_dist = std::accumulate(dist.begin(), dist.end(), 0.0 ,std::plus<double>());

    std::cout << total_dist << std::endl;

    return 1; 
}
