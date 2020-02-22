#include <iostream>
#include <queue>

using namespace std;

class MyStack {
   private:
    queue<int> q;
    queue<int> aux;

   public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (q.size() != 1) {
            aux.push(q.front());
            q.pop();
        }
        int result = q.front();
        q.pop();
        swap(aux, q);
        return result;
    }

    /** Get the top element. */
    int top() {
        while (q.size() != 1) {
            aux.push(q.front());
            q.pop();
        }
        int result = q.front();
        aux.push(result);
        swap(q, aux);
        return result;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty() && aux.empty();
    }
};

int main() {
    MyStack st;
    st.push(1);
    st.push(2);
    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.empty() << endl;

    return 0;
}
