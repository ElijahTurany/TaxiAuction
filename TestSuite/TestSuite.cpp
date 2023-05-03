#include "pch.h"
#include "CppUnitTest.h"
#include "../TaxiAuction/AdaptablePriorityQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSuite
{
	TEST_CLASS(TestSuite)
	{
	public:
		
		TEST_METHOD(EnqueueOneItem) {
			maxHeap h;
			h.enqueue(1, "a");
			pair<int, string> p = h.dequeue();
			Assert::AreEqual(true, p.first == 1);
			Assert::AreEqual(true, p.second == "a");
		}

		TEST_METHOD(EnqueueThreeItems) {
			maxHeap h;
			h.enqueue(1, "a");
			h.enqueue(2, "b");
			h.enqueue(3, "c");
			pair<int, string> p1 = h.dequeue();
			pair<int, string> p2 = h.dequeue();
			pair<int, string> p3 = h.dequeue();
			Assert::AreEqual(true, p1.second == "c");
			Assert::AreEqual(true, p2.second == "b");
			Assert::AreEqual(true, p3.second == "a");
		}

		TEST_METHOD(Peek) {
			maxHeap h;
			h.enqueue(1, "a");
			h.enqueue(2, "b");
			h.enqueue(3, "c");
			pair<int, string> p = h.peek();
			Assert::AreEqual(true, p.first == 3);
			Assert::AreEqual(true, p.second == "c");
			h.dequeue();
			p = h.peek();
			Assert::AreEqual(true, p.first == 2);
			Assert::AreEqual(true, p.second == "b");
			h.dequeue();
			p = h.peek();
			Assert::AreEqual(true, p.first == 1);
			Assert::AreEqual(true, p.second == "a");
		}

		TEST_METHOD(RemoveAny) {
			maxHeap h;
			h.enqueue(1, "a");
			h.enqueue(2, "b");
			h.enqueue(3, "c");
			h.removeAny("c");
			pair<int, string> p = h.peek();
			Assert::AreEqual(true, p.first == 2);
			Assert::AreEqual(true, p.second == "b");
			h.removeAny("b");
			p = h.peek();
			Assert::AreEqual(true, p.first == 1);
			Assert::AreEqual(true, p.second == "a");
		}

		TEST_METHOD(EnqueueDequeuePeekRemove) {
			maxHeap h;
			h.enqueue(5, "e");
			h.enqueue(4, "d");
			h.enqueue(2, "b");
			h.enqueue(3, "c");
			h.enqueue(1, "a");
			h.enqueue(6, "f");
			pair<int, string> p = h.peek();
			Assert::AreEqual(true, p.second == "f");
			h.dequeue();
			p = h.dequeue();
			Assert::AreEqual(true, p.second == "e");
			h.removeAny("d");
			h.removeAny("a");
			p = h.peek();
			Assert::AreEqual(true, p.second == "c");
			h.dequeue();
			h.enqueue(7, "g");
			p = h.dequeue();
			Assert::AreEqual(true, p.second == "g");
			p = h.dequeue();
			Assert::AreEqual(true, p.second == "b");
		}
	};
}
