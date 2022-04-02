class Table
{
    private:
        // wskaznik na pierwszy element tablicy
        int * start;
        // zmienna przechowujaca rozmiar tablicy
        unsigned size;
    public:
        Table();
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

        // wyszukanie elementu w tablicy
        void search(int value);

        void fill_random(int quantity, int range);

        // wypisanie listy
        void print();
};