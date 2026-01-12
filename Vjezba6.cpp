#include <iostream>

class container {
private:
    int* data_;
    unsigned long size_;
    unsigned long capacity_;

public:
    container(unsigned long initial_capacity = 0)
        : data_(0), size_(0), capacity_(initial_capacity)
    {
        if (capacity_ > 0)
            data_ = new int[capacity_];

        std::cout << "Default ctor (capacity=" << capacity_ << ")\n";
    }

    container(const container& other)
        : data_(0), size_(other.size_), capacity_(other.capacity_)
    {
        if (capacity_ > 0) {
            data_ = new int[capacity_];
            for (unsigned long i = 0; i < size_; ++i)
                data_[i] = other.data_[i];
        }

        std::cout << "Copy ctor\n";
    }

    container(container&& other)
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_)
    {
        other.data_ = 0;
        other.size_ = 0;
        other.capacity_ = 0;

        std::cout << "Move ctor\n";
    }

    ~container()
    {
        delete[] data_;
        std::cout << "Destructor\n";
    }

    void push_back(int value)
    {
        if (size_ == capacity_) {
            unsigned long new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            int* new_data = new int[new_capacity];

            for (unsigned long i = 0; i < size_; ++i)
                new_data[i] = data_[i];

            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;

            std::cout << "Reallocation to capacity " << capacity_ << "\n";
        }

        data_[size_++] = value;
    }

    unsigned long size() const
    {
        return size_;
    }

    unsigned long capacity() const
    {
        return capacity_;
    }

    int& at(unsigned long index)
    {
        if (index >= size_) {
            std::cout << "Index out of range\n";
            return data_[0]; 
        }
        return data_[index];
    }

    const int& at(unsigned long index) const
    {
        if (index >= size_) {
            std::cout << "Index out of range\n";
            return data_[0];
        }
        return data_[index];
    }

    void clear()
    {
        size_ = 0;
    }
};

void process(container c)
{
    std::cout << "Function received container, size = " << c.size() << "\n";
}

container create_container()
{
    container c;
    c.push_back(100);
    c.push_back(200);
    return c;
}

int main()
{
    std::cout << "1. Default konstruktor i dodavanje elemenata\n";
    container a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    std::cout << "\n2. Copy konstruktor\n";
    container b = a;

    std::cout << "\n3. Move konstruktor\n";
    container c = (container&&)a;

    std::cout << "\n4. Prosljeđivanje po vrijednosti\n";
    process(b);

    std::cout << "\n5. Vraćanje iz funkcije\n";
    container d = create_container();

    std::cout << "\n6. Realokacija memorije\n";
    container e;
    for (int i = 0; i < 10; ++i)
        e.push_back(i * 10);

    std::cout << "\n7. Ispis elemenata\n";
    for (unsigned long i = 0; i < e.size(); ++i)
        std::cout << "Index " << i << ": " << e.at(i) << "\n";

    return 0;
}
