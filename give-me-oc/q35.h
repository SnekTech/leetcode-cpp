//
// Created by syf on 2023/3/15.
//

#ifndef LEETCODE_CPP_Q35_H
#define LEETCODE_CPP_Q35_H

#include <unordered_map>
#include "ListNode.h"

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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;

        std::unordered_map<Node*, Node*> originToReplicate = {
            { nullptr, nullptr}
        };

        auto dummy = Node(-1);
        auto prev = &dummy;
        auto p = head;
        while (p != nullptr) {
            prev->next = new Node(p->val);

            originToReplicate[p] = prev->next;

            prev = prev->next;
            p = p->next;
        }

        p = head;
        while (p != nullptr) {
            auto replicate = originToReplicate[p];
            auto replicateRandom = originToReplicate[p->random];
            replicate->random = replicateRandom;

            p = p->next;
        }

        return dummy.next;
    }
};

#endif //LEETCODE_CPP_Q35_H
