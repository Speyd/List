using namespace std;

template <typename T>
class Node {

public:

    T value;
    Node* next;

    Node(const T& valueP) :value{ valueP }, next{ nullptr } {}

};