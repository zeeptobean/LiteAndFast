namespace LAF
{
    template<class T>
    struct Vector
    {
        private:
        T * _dat;
        int _size = 0;
        int _last_ptr = -1;
        public:
        T& operator[](int idx)
        {
            if (idx >= 0)
                return _dat[idx];
            return _dat[_last_ptr + idx + 1];
        }
        const T& operator[](int idx) const
        {
            if (idx >= 0)
                return _dat[idx];
            return _dat[_last_ptr + idx + 1];
        }
        const int size() const
        {
            return _last_ptr + 1;
        }

        T* begin()
        {
            return _dat;
        }

        T* end()
        {
            return _dat + _last_ptr + 1;
        }

        ~Vector()
        {
            delete[]_dat;
        }

        Vector()
        {
            _last_ptr = -1;
        }

        Vector(std::initializer_list<T> ls)
        {
            _dat = new T[ls.size()];
            memmove(_dat,ls.begin(),sizeof(T) * ls.size());
            _size = ls.size();
            _last_ptr = ls.size() - 1;
        }

        Vector(int Size, T (*func)(int idx))
        {
            _dat = new T[Size];
            _size = Size;
            _last_ptr = _size - 1;
            for (int i = 0; i < Size;i++)
            {
                _dat[i] = func(i);
            }
        }
        template<class it>
        Vector(it beg, it en)
        {
            int Size = std::distance(beg,en);
            _size = Size;
            _dat = new T[_size];
            _last_ptr = _size - 1;
            int idx = 0;
            while (beg != en)
            {
                _dat[idx++] = *beg;
                beg++;
            }
        }

        void fake_clear()
        {
            _last_ptr = -1;
        }

        void clear()
        {
            _last_ptr = -1;
            delete[] _dat;
            _size = 0;
        }

        void init(int Size)
        {
            _dat = new T[Size];
            _size=Size;
        }

        void push_back(const T &value)
        {
            if (!_size)
            {
                _size = 1;
                _dat = new T[1];
            } else if (_last_ptr == _size - 1)
            {
                _size *= 2;
                T* old = _dat;
                _dat = new T[_size];
                memmove(_dat,old,sizeof(T) * (_size/2));
                delete[]old;
            }
            _dat[++_last_ptr] = value;
        }

    };



    template<typename T>
    std::ostream& operator<< (std::ostream& out, const Vector<T>& arr)
    {
        out << "[ ";

        for (int i = 0; i < arr.size();i++)
        {
            out << arr[i] << " ";
        }
        out << "]";
    }


}
