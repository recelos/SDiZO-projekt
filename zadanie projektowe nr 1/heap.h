class Heap
{
    private:
        int * array;
        int size;
        void heapify(int root_index);
        void build_max_heap();

    public:
        Heap();
        void extract_max();
        void add(int value);
        void print();
        void search(int value);
        void fill_random(int quantity, int range);
};