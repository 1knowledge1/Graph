#include <iostream>
template <typename T>
class queue_t
{
    struct node_t {
        node_t *next;
        T value;
    };
    node_t * head;
    node_t * tail;
public:
    queue_t() {
        head = nullptr;
        tail = nullptr;
    }
    queue_t(queue_t & other) {
        head = nullptr;
		tail = nullptr;
		for (node_t* n =other.head; n != nullptr; n = n->next) {
			push(n->value);
		}
    }
    ~queue_t() {
        if (head == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        while (head != nullptr) {
            pop();
        }
        head = nullptr;
        tail = nullptr;
        return;
    }
    void push(T value) {
        if (!head) {
            head = new node_t;
            head->next = nullptr;
            head->value = value;
            tail = head;
        }
        else {
            tail->next = new node_t;
            tail->next->value = value;
            tail->next->next = nullptr;
            tail = tail->next;
        }
    }
    T pop() {
        if (head) {
            T del_val = head->value;
            node_t *tmp = head->next;
            if (head == tail) {
                tmp = nullptr;
                tail = nullptr;
            }
            delete head;
            head = tmp;
            return del_val;
        }
        else {
            throw "Queue is empty.";
        }
    }
    void print(std::ostream & stream) {
        if (head) {
            node_t *print = head;
            while (print) {
                stream << print->value;
                print = print->next;
                if (print) stream << "--->";
            }
            stream << '\n';
            delete print;
        }
        else
        {
            stream << "Can't print: queue is empty.\n";
        }
    }
};
