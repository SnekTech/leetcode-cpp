//
// Created by syf on 2023/3/20.
//

#ifndef LEETCODE_CPP_Q146_H
#define LEETCODE_CPP_Q146_H

#include <deque>
#include <unordered_map>

struct DLinkedNode
{
	int key, value;
	DLinkedNode* prev;
	DLinkedNode* next;

	DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr)
	{
	}

	DLinkedNode(int key, int value)
		: key(key), value(value), prev(nullptr), next(nullptr)
	{
	}
};

class LRUCache
{
public:
	std::unordered_map<int, DLinkedNode*> cache;
	DLinkedNode* head;
	DLinkedNode* tail;
	int size, capacity;
	LRUCache(int _capacity): capacity(_capacity), size(0)
	{
		head = new DLinkedNode();
		tail = new DLinkedNode();
		head->next = tail;
		tail->prev = head;
	}

	int get(int key)
	{
		if (!cache.count(key)) return -1;

		DLinkedNode* node = cache[key];
		moveToHead(node);
		return node->value;
	}

	void put(int key, int value)
	{
		if (!cache.count(key))
		{
			auto node = new DLinkedNode(key, value);
			cache[key] = node;
			addToHead(node);
			size++;

			if (size > capacity)
			{
				auto removed = removeTail();
				cache.erase(removed->key);
				delete removed;
				size--;
			}

			return;
		}

		auto node = cache[key];
		node->value = value;
		moveToHead(node);
	}

	void addToHead(DLinkedNode* node)
	{
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}

	void removeNode(DLinkedNode* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	void moveToHead(DLinkedNode* node)
	{
		removeNode(node);
		addToHead(node);
	}

	DLinkedNode* removeTail()
	{
		DLinkedNode* node = tail->prev;
		removeNode(node);
		return node;
	}
};

#endif //LEETCODE_CPP_Q146_H
