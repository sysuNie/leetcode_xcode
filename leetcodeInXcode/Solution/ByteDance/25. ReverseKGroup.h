//
//  25. ReverseKGroup.h
//  leetcodeInXcode
//
//  Created by niejikang on 12.5.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _5__ReverseKGroup_h
#define _5__ReverseKGroup_h

/**
 206 反转链表
 25. k个一组翻转链表
 160. 相交链表
 21. 合并两个有序链表
 19. 删除链表的倒数第N个节点
 141. 环形链表
 82. 删除链表中重复的元素
 142. 环形链表
 143. 重排链表
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// 翻转 [head, tail] 这段链表，返回新头
// tail->next 不动，翻转后 head->next 指向原 tail->next
std::pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
  ListNode* prev = tail->next; // prev 初始指向 tail->next，作为终止条件
  ListNode* cur = head;
  while (prev != tail) {      // 翻转直到 cur == tail
    ListNode* next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return {tail, head};        // 翻转后 tail 是新头，head 是新尾
}

ListNode* reverseKGroup(ListNode* head, int k) {
  // 哨兵节点，简化头节点处理
  ListNode dummy(0);
  dummy.next = head;
  ListNode* pre = &dummy;   // pre 始终指向待翻转段的前一个节点

  while (head != nullptr) {
    // 找到第 k 个节点作为 tail
    ListNode* tail = pre;
    for (int i = 0; i < k; i++) {
      tail = tail->next;
      if (tail == nullptr) return dummy.next; // 不足 k 个，直接返回
    }

    ListNode* next = tail->next; // 记录下一段的起点

    // 翻转 [head, tail]
    auto [new_head, new_tail] = reverse(head, tail);

    // 接回主链表
    pre->next = new_head;
    new_tail->next = next;

    // 移动指针到下一段
    pre = new_tail;
    head = next;
  }

  return dummy.next;
}

// 测试
int test() {
  // 构造链表 1->2->3->4->5
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  head = reverseKGroup(head, 2); // 期望: 2->1->4->3->5

  for (auto p = head; p; p = p->next)
    std::cout << p->val << " ";
  return 0;
}

class Singleton
{
public:
    static Singleton& getInstance()
    {
        static Singleton singleton;
        return singleton;
    }
    
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() = default;
    ~Singleton() = default;
};

// 四叉树 QuadTree
struct Point {
    int id;
    float x;
    float y;
};

struct Rect {
    float x1;
    float y1;
    float x2;
    float y2;

    bool contains(float x, float y) const {
        return x >= x1 && x <= x2 && y >= y1 && y <= y2;
    }

    bool intersects(const Rect& other) const {
        return !(other.x2 < x1 || other.x1 > x2 ||
                 other.y2 < y1 || other.y1 > y2);
    }
};

class QuadTree {
private:
    static constexpr int CAPACITY = 4;
    static constexpr int MAX_DEPTH = 16;

    enum ChildIndex {
        NW = 0,
        NE = 1,
        SW = 2,
        SE = 3
    };

    Rect bounds_;
    int depth_ = 0;
    bool divided_ = false;

    std::vector<Point> points_;
    std::unique_ptr<QuadTree> children_[4];

public:
    explicit QuadTree(const Rect& bounds, int depth = 0)
        : bounds_(bounds), depth_(depth) {}

    bool insert(const Point& point) {
        if (!bounds_.contains(point.x, point.y)) {
            return false;
        }

        if (!divided_) {
            if (points_.size() < CAPACITY || depth_ >= MAX_DEPTH) {
                points_.push_back(point);
                return true;
            }

            subdivide();
        }

        return insertToChild(point);
    }

    void queryRange(const Rect& query, std::vector<int>& result) const {
        if (!bounds_.intersects(query)) {
            return;
        }

        if (!divided_) {
            for (const auto& point : points_) {
                if (query.contains(point.x, point.y)) {
                    result.push_back(point.id);
                }
            }
            return;
        }

        for (const auto& child : children_) {
            if (child) {
                child->queryRange(query, result);
            }
        }
    }

private:
    void subdivide() {
        float midX = (bounds_.x1 + bounds_.x2) * 0.5f;
        float midY = (bounds_.y1 + bounds_.y2) * 0.5f;

        children_[NW] = std::make_unique<QuadTree>(
            Rect{bounds_.x1, midY, midX, bounds_.y2}, depth_ + 1);

        children_[NE] = std::make_unique<QuadTree>(
            Rect{midX, midY, bounds_.x2, bounds_.y2}, depth_ + 1);

        children_[SW] = std::make_unique<QuadTree>(
            Rect{bounds_.x1, bounds_.y1, midX, midY}, depth_ + 1);

        children_[SE] = std::make_unique<QuadTree>(
            Rect{midX, bounds_.y1, bounds_.x2, midY}, depth_ + 1);

        divided_ = true;

        std::vector<Point> oldPoints;
        oldPoints.swap(points_);

        for (const auto& point : oldPoints) {
            insertToChild(point);
        }
    }

    bool insertToChild(const Point& point) {
        for (auto& child : children_) {
            if (child && child->insert(point)) {
                return true;
            }
        }

        return false;
    }
};

#endif /* _5__ReverseKGroup_h */
