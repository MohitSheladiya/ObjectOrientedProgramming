// Workshop 9:
// Collection template
// 2021-03-26
// Version: 1.0 
// Author: Fardad Soleimanloo
/////////////////////////////////////////////
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
namespace sdds {
    template <typename Temp>
    class Collection {
        Temp* m_data = nullptr;
        int m_size = 0;
    public:
        Collection(int size = 0);
        Collection(const Collection<Temp>& CP);
        Collection<Temp>& operator=(const Collection<Temp>& RO);
        int size()const;
        void resize(int newsize);
        Temp& operator[](int index);
        Collection<Temp>& add(const Temp& element);
        ~Collection();
    };

    template <typename Temp>
    Collection<Temp>::Collection(int size) :m_size(size) {
        if (m_size <= 0) m_size = 0;
        if (m_size > 0) m_data = new Temp[m_size];
    }
    template <typename Temp>
    Collection<Temp>::Collection(const Collection<Temp>& CP) {
        operator=(CP);
    }
    template <typename Temp>
    Collection<Temp>& Collection<Temp>::operator=(const Collection<Temp>& RO) {
        if (this != &RO) {
            delete[] m_data;
            m_data = new Temp[m_size = RO.m_size];
            for (int i = 0; i < m_size; i++) m_data[i] = RO.m_data[i];
        }
        return *this;
    }

    template <typename Temp>
    int Collection<Temp>::size()const {
        return m_size;
    }

    template <typename Temp>
    void Collection<Temp>::resize(int newsize) {
        int i;
        Temp* temp = nullptr;
        if (newsize < 0) newsize = 0;
        if (newsize > 0) {
            temp = new Temp[newsize];
            for (i = 0; i < m_size && i < newsize; i++) {
                temp[i] = m_data[i];
            }
        }
        delete[] m_data;
        m_data = temp;
        m_size = newsize;
    }

    template <typename Temp>
    Temp& Collection<Temp>::operator[](int index) {
        if (index >= m_size) resize(index + 1);
        return m_data[index];
    }

    template <typename Temp>
    Collection<Temp>& Collection<Temp>::add(const Temp& element) {
        (*this)[size()] = element;
        return *this;
    }
    template <typename Temp>
    Collection<Temp>::~Collection() {
        delete[] m_data;
    }
}

#endif // !SDDS_COLLECTION_H_