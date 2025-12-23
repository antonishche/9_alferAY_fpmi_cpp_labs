#include "forward_list_impl.h"

// your code goes here

#include <stdexcept>

ForwardList::ForwardList() : head_(nullptr), tail_(nullptr), size_(0) {
}

void ForwardList::PushFront(int32_t value) {
    Node* new_node = new Node(value);

    if (head_ == nullptr) {
        tail_ = head_ = new_node;
    } else {
        new_node->next_ = head_;
        head_ = new_node;
    }

    size_++;
}

void ForwardList::PopFront() {
    if (head_ == nullptr)
        return;

    Node* to_delete = head_;
    head_ = head_->next_;

    if (head_ == nullptr) {
        tail_ = nullptr;
    }

    delete to_delete;
    size_--;
}

int32_t ForwardList::Front() const {
    if (head_ != nullptr) {
        // throw std::runtime_error("List is empty");
        return head_->value_;
    }
}

size_t ForwardList::Size() const {
    return size_;
}

void ForwardList::Clear() {
    Node* current = head_;

    while (current != nullptr) {
        Node* next = current->next_;
        delete current;
        current = next;
    }

    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

void ForwardList::Print(std::ostream& out) {
    Node* current = head_;

    while (current != nullptr) {
        out << current->value_;
        current = current->next_;
        if (current != nullptr) {
            out << ' ';
        }
    }
}

bool ForwardList::FindByValue(int32_t value) {
    Node* current = head_;

    while (current != nullptr) {
        if (current->value_ == value) {
            return true;
        }
        current = current->next_;
    }

    return false;
}

void ForwardList::Remove(int32_t value) {
    Node* current = head_;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->value_ == value) {
            Node* to_delete = current;

            if (prev == nullptr) {
                head_ = current->next_;
            } else {
                prev->next_ = current->next_;
            }

            current = current->next_;

            if (to_delete == tail_) {
                tail_ = prev;
            }

            delete to_delete;
            --size_;

        } else {
            prev = current;
            current = current->next_;
        }
    }
}

ForwardList::ForwardList(size_t count, int32_t value) : head_(nullptr), tail_(nullptr), size_(0) {
    for (size_t i = 0; i < count; i++) {
        PushBack(value);
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init)
    : head_(nullptr), tail_(nullptr), size_(0) {
    for (int32_t item : init) {
        PushBack(item);
    }
}

ForwardList& ForwardList::operator=(const ForwardList& other) {
    if (this != &other) {
        Clear();
        Node* current = other.head_;
        while (current != nullptr) {
            PushBack(current->value_);
            current = current->next_;
        }
    }
    return *this;
}

ForwardList::~ForwardList() {
    Clear();
}

ForwardList::ForwardList(const ForwardList& other) : head_(nullptr), tail_(nullptr), size_(0) {
    Node* current = other.head_;

    while (current != nullptr) {
        PushBack(current->value_);
        current = current->next_;
    }
}