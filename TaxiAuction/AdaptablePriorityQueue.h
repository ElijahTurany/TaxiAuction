#pragma once
#include <vector>
#include <iostream>
using namespace std;

class maxHeap {
private:
	//Used to store data, bid is first followed by name
	vector<pair<int, string>> data;
	int size{ 0 };
	//reheapifyUp method from class changed to use vector of pairs
	void reheapifyUp(int index) {
		if (index <= 1) {
			return;
		}
		if (data[index / 2].first >= data[index].first) {
			return;
		}
		else {
			pair<int, string> tmp = data[index];
			data[index] = data[index / 2];
			data[index / 2] = tmp;
			reheapifyUp(index / 2);
		}
	}
	//reheapifyDown method from class changed to use vector of pairs
	void reheapifyDown(int index) {
		if (index * 2 > size) { return; }
		if ((data[index].first >= data[index * 2].first) && (data[index].first >= data[index * 2 + 1].first)) { return; }
		if (index * 2 == size) {
			if (data[index].first < data[index * 2].first) {
				pair<int, string> tmp = data[index];
				data[index] = data[index * 2];
				data[index * 2] = tmp;
			}
			return;
		}

		if (data[index * 2].first >= data[index * 2 + 1].first) {
			pair<int, string> tmp = data[index];
			data[index] = data[index * 2];
			data[index * 2] = tmp;
			reheapifyDown(index * 2);
		}
		else {
			pair<int, string> tmp = data[index];
			data[index] = data[index * 2 + 1];
			data[index * 2 + 1] = tmp;
			reheapifyDown(index * 2 + 1);
		}
	}
public:
	//Heap index starts at 1, so a blank item needs to be pushed to the vector
	maxHeap() {
		pair<int, string> p{ 0, "" };
		data.push_back(p);
	}
	//Pushes new pair to vector, calls reheapifyUp on the new element, and increments size
	void enqueue(int bid, string name) {
		pair<int, string> p{ bid, name };
		data.push_back(p);
		reheapifyUp(size + 1);
		size++;
	}
	pair<int, string> dequeue() {
		//Returns a blank pair if the size is 0
		if (size == 0) {
			pair<int, string> returnMe{ 0, "" };
			return returnMe;
		}
		//Grabs the root of the heap as a pair
		pair<int, string> returnMe = data[1];
		//Puts the last item at the root
		data[1] = data[size];
		//Decrement size, call reaheapifyDown on new root
		size--;
		reheapifyDown(1);
		//Delete the last item in data, return pair that was the first element
		data.pop_back();
		return returnMe;
	}
	//Returns a blank pair if size is 0, otherwise returns root
	pair<int, string> peek() {
		if (size == 0) {
			pair<int, string> returnMe{ 0, "" };
			return returnMe;
		}
		return data[1];
	}
	void removeAny(string name) {
		//If the item to remove is the root, calls dequeue
		if (this->peek().second == name) {
			this->dequeue();
		}
		int removeIndex = 0;
		//Runs a for loop to see if the name is in the heap
		for (int i = 1; i <= size; i++) {
			if (data[i].second == name) {
				removeIndex = i;
			}
		}
		//If the name wasn't found (index remained 0), returns
		if (removeIndex == 0) {return;}
		//Otherwise moves the last item in the heap to the location of the item being removed,
		data[removeIndex] = data[size];
		//deletes the last item in the heap,
		data.pop_back();
		//decrements size, and calls reheapifyDown on the location of the removed item
		size--;
		reheapifyDown(removeIndex);
	}
	//Prints the heap as pairs In parentheses
	void print() {
		for (int i = 1; i <= size; i++) {
			cout << "(" << data[i].second << ": " << data[i].first << ") ";
		}
		cout << endl;
	}
};