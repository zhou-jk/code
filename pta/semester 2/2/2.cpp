#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class List
{
private:
    struct Node
    {
        T value;
        Node *prev, *next;
        Node(const T &val = T(), Node *p = nullptr, Node *n = nullptr) : value(val), prev(p), next(n) {}
    };

    Node *sentinel;
    size_t list_size;

public:
    List() : list_size(0)
    {
        sentinel = new Node();
        sentinel->next = sentinel->prev = sentinel;
    }

    ~List()
    {
        clear();
        delete sentinel;
    }

    List(const List &other) : list_size(0)
    {
        sentinel = new Node();
        sentinel->next = sentinel->prev = sentinel;
        Node *current = other.sentinel->next;
        while (current != other.sentinel)
        {
            push_back(current->value);
            current = current->next;
        }
    }
    List &operator=(List other)
    {
        swap(*this, other);
        return *this;
    }

    T front() const
    {
        return sentinel->next->value;
    }

    T back() const
    {
        return sentinel->prev->value;
    }

    List(List &&other) : sentinel(other.sentinel), list_size(other.list_size)
    {
        other.sentinel = nullptr;
        other.list_size = 0;
    }

    List &operator=(List &&other)
    {
        if (this != &other)
        {
            clear();
            delete sentinel;

            sentinel = other.sentinel;
            list_size = other.list_size;

            other.sentinel = nullptr;
            other.list_size = 0;
        }
        return *this;
    }

    void push_front(T val)
    {
        Node *node = new Node(val);
        node->next = sentinel->next;
        node->prev = sentinel;
        sentinel->next->prev = node;
        sentinel->next = node;
        ++list_size;
        return;
    }

    void push_back(T val)
    {
        Node *node = new Node(val);
        node->prev = sentinel->prev;
        node->next = sentinel;
        sentinel->prev->next = node;
        sentinel->prev = node;
        ++list_size;
        return;
    }

    void pop_front()
    {
        if (list_size == 0)
        {
            throw std::runtime_error("Cannot pop from an empty list.");
        }
        Node *temp = sentinel->next;
        sentinel->next = temp->next;
        temp->next->prev = sentinel;
        delete temp;
        --list_size;
        return;
    }

    void pop_back()
    {
        if (list_size == 0)
        {
            throw std::runtime_error("Cannot pop from an empty list.");
        }
        Node *temp = sentinel->prev;
        sentinel->prev = temp->prev;
        temp->prev->next = sentinel;
        delete temp;
        --list_size;
        return;
    }

    size_t size() const
    {
        return list_size;
    }

    bool empty() const
    {
        return list_size == 0;
    }

    void clear()
    {
        while (list_size > 0)
        {
            pop_front();
        }
        return;
    }

    class iterator
    {
        friend class List<T>;

    private:
        Node *current_node;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using const_pointer = T *;
        using const_reference = T &;
        using iterator_category = std::bidirectional_iterator_tag;

        iterator(Node *node) : current_node(node) {}

        iterator &operator++()
        {
            if (current_node)
            {
                current_node = current_node->next;
            }
            return *this;
        }
        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        iterator &operator--()
        {
            if (current_node)
            {
                current_node = current_node->prev;
            }
            return *this;
        }
        iterator operator--(int)
        {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }

        T &operator*()
        {
            return current_node->value;
        }
        const_pointer operator->() const
        {
            return &(current_node->value);
        }

        bool operator==(const iterator &other) const
        {
            return current_node == other.current_node;
        }
        bool operator!=(const iterator &other) const
        {
            return current_node != other.current_node;
        }
    };

    iterator insert(iterator pos, const T &value)
    {
        Node *current_node = pos.current_node;
        Node *newNode = new Node(value);
        newNode->prev = current_node->prev;
        newNode->next = current_node;
        current_node->prev->next = newNode;
        current_node->prev = newNode;
        ++list_size;
        return iterator(newNode);
    }

    iterator erase(iterator pos)
    {
        if (list_size == 0)
        {
            throw std::runtime_error("Cannot erase from an empty list.");
        }
        Node *to_erase = pos.current_node;
        if (to_erase == sentinel)
        {
            throw std::runtime_error("Cannot erase the end iterator.");
        }
        to_erase->prev->next = to_erase->next;
        to_erase->next->prev = to_erase->prev;
        iterator nextIter(to_erase->next);
        delete to_erase;
        --list_size;
        return nextIter;
    }

    iterator begin()
    {
        return iterator(sentinel->next);
    }

    iterator end()
    {
        return iterator(sentinel);
    }

    template <class Compare>
    void merge(List &x, Compare comp = std::less<T>())
    {
        Node *node1 = this->sentinel->next;
        Node *node2 = x.sentinel->next;

        while (node1 != this->sentinel && node2 != x.sentinel)
        {
            if (comp(node2->value, node1->value))
            {
                Node *next2 = node2->next;
                node2->prev->next = node2->next;
                node2->next->prev = node2->prev;

                node2->next = node1;
                node2->prev = node1->prev;
                node1->prev->next = node2;
                node1->prev = node2;

                node2 = next2;
            }
            else
            {
                node1 = node1->next;
            }
        }

        if (node2 != x.sentinel)
        {
            this->sentinel->prev->next = node2;
            node2->prev = this->sentinel->prev;

            this->sentinel->prev = x.sentinel->prev;
            x.sentinel->prev->next = this->sentinel;
        }

        x.sentinel->next = x.sentinel->prev = x.sentinel;
        x.list_size = 0;
        return;
    }
};

template <typename T>
class Stack
{
private:
    List<T> l;

public:
    Stack() {}

    ~Stack()
    {
        l.clear();
    }

    size_t size() const
    {
        return l.size();
    }

    bool empty() const
    {
        return l.empty();
    }

    T top() const
    {
        return l.back();
    }

    void push(const T &x)
    {
        return l.push_back(x);
    }

    void pop()
    {
        return l.pop_back();
    }
};
int main()
{
    int x;
    Stack<int> s;
    while (std::cin >> x)
    {
        s.push(x);
    }
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
        std::cout << s.size() << "\n";
    }
    return 0;
}