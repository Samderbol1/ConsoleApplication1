#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm> // include this header file
using namespace std;

// Define a struct to store book information
struct Book {
    string id; // book number
    string name; // book name
    double price; // book price
};

// Define a function to compare two books by price
bool compareByPrice(const Book& a, const Book& b) {
    return a.price > b.price;
}

int main() {
    int n; // number of books
    cin >> n; // input n
    vector<Book> books(n); // create a vector of n books
    for (int i = 0; i < n; i++) {
        cin >> books[i].id >> books[i].name >> books[i].price; // input book information
    }
    std::sort(books.begin(), books.end(), compareByPrice); // use std::sort instead of sort
    double maxPrice = books[0].price; // get the maximum price
    int m = 0; // number of most expensive books
    for (int i = 0; i < n; i++) {
        if (books[i].price == maxPrice) { // if the book has the same price as the maximum price
            m++; // increase the count of most expensive books
        }
        else { // otherwise, stop the loop
            break;
        }
    }
    cout << m << endl; // output the number of most expensive books
    for (int i = 0; i < m; i++) {
        cout << books[i].id << " " << books[i].name << " " << fixed << setprecision(2) << books[i].price << endl; // output the most expensive book information with two decimal places for price
    }
    return 0;
}