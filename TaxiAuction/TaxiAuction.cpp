#include <iostream>
#include "AdaptablePriorityQueue.h"
using namespace std;

int main() {
    int input = 0;
    maxHeap h;
    while (input != 6) {
        cout << "Enter a number\n1 to add a new bid\n2 to get the highest bid\n3 to remove the highest bid\n4 to remove a bid by name\n5 to print all bids\n6 to quit\n";
        cin >> input;
        if (input == 1) {
            string name;
            int bid;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter bid: ";
            cin >> bid;
            h.enqueue(bid, name);
        }
        if (input == 2) {
            pair<int, string> top = h.peek();
            cout << "Name: " << top.second << " Bid: " << top.first << endl;
        }
        if (input == 3) {
            pair<int, string> top = h.dequeue();
            cout << "Name: " << top.second << " Bid: " << top.first << " Removed" << endl;
        }
        if (input == 4) {
            string name;
            cout << "Enter name: ";
            cin >> name;
            h.removeAny(name);
        }
        if (input == 5) {
            h.print();
        }
    }   
}