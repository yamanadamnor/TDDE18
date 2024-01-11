#include "kcats.h"
KCats::~KCats() {
    while(!empty()) {
        pop();
    }
}
KCats::KCats(KCats&& newCat) {
    last = newCat.last;
    newCat.last = nullptr;
}

KCats& KCats::operator=(KCats &&rhs) {
    last = rhs.last;
    rhs.last = nullptr;

    return *this;
}


void KCats::push(int data) {
    last = new Node{data, last};
}

bool KCats::empty() const {
    return last == nullptr;
}

int KCats::pop() {
    Node* next{last->next};
    int value{last->value};
    delete last;
    last = next;

    return value;
}
