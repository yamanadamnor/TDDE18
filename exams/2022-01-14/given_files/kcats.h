class KCats
{
public:
    KCats();
    KCats(KCats const&);
    KCats(KCats&&);
    ~KCats();

    KCats& operator=(KCats const&);
    KCats& operator=(KCats&&);

    bool empty();
    void push(int data);
    int pop();
};
