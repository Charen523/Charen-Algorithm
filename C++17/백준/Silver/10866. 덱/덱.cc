#include <iostream>
#include <string>

using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(const int v) : value(v), prev(nullptr), next(nullptr) {}
};

class Stack {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Stack() : head(nullptr), tail(nullptr), count(0) {}

    ~Stack() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(int v) {
        Node* newNode = new Node(v);
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;  // 기존 head의 prev 갱신
        } else {
            tail = newNode;  // 리스트가 비어있다면 tail도 업데이트
        }

        head = newNode;
        count++;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;  // 기존 tail의 next 갱신
        } else {
            head = newNode;  // 리스트가 비어있다면 head도 업데이트
        }

        tail = newNode;
        count++;
    }

    void pop_front() {
        if (count == 0) {
            cout << -1 << '\n';
            return;
        }

        cout << head->value << '\n';
        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;  // 원소가 1개였을 경우 tail도 null로 설정
        }

        delete temp;
        count--;
    }

    void pop_back() {
        if (count == 0) {
            cout << -1 << '\n';
            return;
        }

        cout << tail->value << '\n';
        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;  // 원소가 1개였을 경우 head도 null로 설정
        }

        delete temp;
        count--;
    }

    void size() const {
        cout << count << '\n';
    }

    void empty() const {
        cout << (count == 0) << '\n';
    }

    void front() const {
        if (count == 0) {
            cout << -1 << '\n';
            return;
        }
        cout << head->value << '\n';
    }

    void back() const {
        if (count == 0) {
            cout << -1 << '\n';
            return;
        }
        cout << tail->value << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int commandCount;
    cin >> commandCount;

    Stack* s = new Stack();
    for (int i = 0; i < commandCount; i++) {
        string command;
        cin >> command;

        if (command == "push_front") {
            int v; cin >> v;
            s->push_front(v);
        }
        else if (command == "push_back") {
            int v; cin >> v;
            s->push_back(v);
        }
        else if (command == "pop_front") {
            s->pop_front();
        }
        else if (command == "pop_back") {
            s->pop_back();
        }
        else if (command == "size") {
            s->size();
        }
        else if (command == "empty") {
            s->empty();
        }
        else if (command == "front") {
            s->front();
        }
        else if (command == "back") {
            s->back();
        }
    }

    delete s;
    return 0;
}
