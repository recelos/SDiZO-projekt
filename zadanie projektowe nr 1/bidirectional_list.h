
class BidirectionalList{

    // struktura przechowująca wartość elementu oraz wskaźniki do poprzedniego i następnego elementu
    struct list_element{
        int value;
        list_element *previous;
        list_element *next;
    };
    
    
    
    public:
        void add_to_beginning(int value);
        void add_to_end(int index);
        void add_to_index(int index, int value);
        void delete_element(int value);
        void delete_beginning();
        void delete_end();
        void search(int value);
        BidirectionalList();
        
        void print();

    private:
        list_element *start;
        unsigned rozmiar;
};

