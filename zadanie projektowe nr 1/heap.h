class Heap
{
    private:
        int * array;
        int size;
        void heapify(int node);
        void heapify_root(int node);
        void build_max_heap();

    public:
        Heap();
        ~Heap();
        void extract_max();
        void add(int value);
        void print();
        void search(int value);
        void search_and_print(int value);
        void fill_random(int quantity, int range);
};