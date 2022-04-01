
class BidirectionalList
{

    // struktura przechowująca wartość elementu oraz wskaźniki do poprzedniego i następnego elementu
    struct list_element
    {
        int value;
        list_element *previous;
        list_element *next;
    };
    public:

        //konstruktor
        BidirectionalList();

        // DODAWANIE ELEMENTU
        // dodanie elementu na poczatek
        void add_to_beginning(int value);
        // dodanie elementu na koniec
        void add_to_end(int index);
        // dodanie elementu w konkretne miejsce 
        void add_to_index(int index, int value);

        // USUWANIE ELEMENTU
        // usuniecie na poczatku
        void delete_beginning();
        // usuniecie na koncu
        void delete_end();
        // usuniecie w konkretnym miejscu
        void delete_at_index(int value);

        // wyszukanie elementu w liscie
        void search(int value);

        // wypisanie listy
        void print();

    private:
        // wskaznik na pierwszy element w liscie
        list_element *start;
        // wskaznik na pierwszy element w liscie
        list_element *final;
        // zmienna przechowujaca rozmiar listy
        unsigned size;
};

