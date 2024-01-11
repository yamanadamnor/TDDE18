#ifndef KCATS_H
#define KCATS_H
class KCats
{
public:
    KCats() = default;
    KCats(KCats&&);
    ~KCats();
    KCats& operator=(KCats&&);

    bool empty() const;
    void push(int data);
    int pop();
private:
    KCats(KCats const&) = delete;
    KCats& operator=(KCats const&) = delete;

    struct Node {
        int value{0};
        Node* next{nullptr};
    };
    Node* last{nullptr};
};
#endif
