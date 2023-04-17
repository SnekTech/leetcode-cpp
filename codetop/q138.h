//
// Created by syf on 2023/4/17.
//

#pragma once
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
using std::unordered_map;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> originToReplicate;
        originToReplicate[nullptr] = nullptr;
        auto p = head;
        Node dummy(-1);
        auto prev = &dummy;

        while (p != nullptr)
        {
            auto replicate = new Node(p->val);
            originToReplicate[p] = replicate;

            prev->next = replicate;
            prev = replicate;
            p = p->next;
        }

        p = head;
        while (p != nullptr)
        {
            auto replicate = originToReplicate[p];
            replicate->random = originToReplicate[p->random];
            p = p->next;
        }

        return dummy.next;
    }
};