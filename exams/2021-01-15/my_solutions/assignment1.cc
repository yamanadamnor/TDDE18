// Given the wishlist:
// Book, Bicycle, Laptop, Socks, Decorations and Candy

// A possible output would be (the order of the entries doesn't
// matter, here they are sorted but they don't have to be):

// What did you get? Book Bicycle
// Candy
// Decorations
// Laptop
// Socks

#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<iostream>

using namespace std;
int main() {
    vector<string> wishlist{ "Book", "Bicycle", "Laptop", "Socks", "Decorations", "Candy" };
    
    cout << "What did you get? ";

    vector<string> gifts { istream_iterator<string>{cin}, istream_iterator<string>{} };
    
    wishlist.erase(
	    remove_if(wishlist.begin(), wishlist.end(), [&gifts](const string &el){
		return find(gifts.begin(), gifts.end(), el) != gifts.end();
	    }),
	    wishlist.end()
    );

    copy(wishlist.begin(), wishlist.end(), ostream_iterator<string>(cout, "\n"));
    return 1;
}
