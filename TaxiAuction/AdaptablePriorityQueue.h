#pragma once
#include <vector>
using namespace std;

class maxHeap {
private:
	vector<pair<int, string>> data;
	int size{ 0 };
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
	maxHeap() {
		pair<int, string> p{ 0, "" };
		data.push_back(p);
	}
	void enqueue(int bid, string name) {
		pair<int, string> p{ bid, name };
		data.push_back(p);
		reheapifyUp(size + 1);
		size++;
	}
	pair<int, string> dequeue() {
		if (size == 0) {
			pair<int, string> returnMe{ 0, "" };
			return returnMe;
		}
		pair<int, string> returnMe = data[1];
		data[1] = data[size];
		size--;
		reheapifyDown(1);
		data.pop_back();
		return returnMe;
	}
	pair<int, string> peek() {
		if (size == 0) {
			pair<int, string> returnMe{ 0, "" };
			return returnMe;
		}
		return data[1];
	}
	void removeAny(string name) {
		int removeIndex = 0;
		for (int i = 1; i <= size; i++) {
			if (data[i].second == name) {
				removeIndex = i;
			}
		}
		if (removeIndex == 0) {return;}
		data[removeIndex] = data[size];
		data.pop_back();
		size--;
		reheapifyDown(removeIndex);
	}
	void print() {
		for (int i = 1; i <= size; i++) {
			cout << "(" << data[i].second << ": " << data[i].first << ") ";
		}
		cout << endl;
	}
};