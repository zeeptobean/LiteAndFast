namespace LAF
{
    template<class T>
    struct Vector
    {
        private:
        T * _dat;
        int _size = 1;          //max size
        int _last_ptr = 0;     //actual size
        int _scaling_factor = 2;

        constexpr void _alloc_mem() {
            T* _old = _dat;
            int _old_size = _size;

            _size *= _scaling_factor;
            _dat = new T[_size];
            memmove(_dat, _old, (size_t) sizeof(T)*_old_size);
            delete[] _old;
        }

        public:
        //factor must be between 2 to 10!
        constexpr void set_scaling_factor(int factor) {
            if(factor < 2 || factor > 10) throw std::invalid_argument("set_scaling_factor need a number between 2 to 10!");
            _scaling_factor = factor;
        }

        //Out-of-bound access is the user's responsibility
        constexpr T& operator[](int idx)
        {
            return _dat[idx];
        }
        constexpr const T& operator[](int idx) const
        {
            return _dat[idx];
        }
        constexpr int size() const
        {
            return _last_ptr;
        }

        constexpr T* begin()
        {
            return _dat;
        }

        constexpr T* end()
        {
            return _dat + _last_ptr;
        }

        ~Vector()
        {
            delete[]_dat;
        }

        constexpr Vector()
        {
            _last_ptr = 0;
        }

        constexpr Vector(std::initializer_list<T> ls)
        {
            _dat = new T[ls.size()];
            memmove(_dat,ls.begin(),sizeof(T) * ls.size());
            _size = ls.size();
            _last_ptr = ls.size();
        }

        constexpr Vector(int Size, T (*func)(int idx))
        {
            _dat = new T[Size];
            _size = Size;
            _last_ptr = _size;
            for (int i = 0; i < Size;i++)
            {
                _dat[i] = func(i);
            }
        }
        template<class it>
        constexpr Vector(it beg, it en)
        {
            int Size = std::distance(beg,en);
            _size = Size;
            _dat = new T[_size];
            _last_ptr = _size;
            int idx = 0;
            while (beg != en)
            {
                _dat[idx++] = *beg;
                beg++;
            }
        }

        constexpr void fake_clear()
        {
            _last_ptr = 0;
        }

        constexpr void clear()
        {
            _last_ptr = 0;
            delete[] _dat;
            _size = 1;
        }

        constexpr void init(int Size)
        {
            _dat = new T[Size];
            _size=Size;
            _last_ptr=0;
        }

        constexpr void push_back(const T &value)
        {
            if (_last_ptr == _size)
            {
                _alloc_mem();
            }
            _dat[_last_ptr++] = value;
        }
        template<typename... Args>
        constexpr void emplace_back(Args&&... args)
        {
            if (_last_ptr == _size)
            {
                _alloc_mem();
            }
            _dat[_last_ptr++] = T(std::forward<Args>(args)...);
        }

    };



    template<typename T>
    constexpr std::ostream& operator<< (std::ostream& out, const Vector<T>& arr)
    {
        out << "[ ";

        for (int i = 0; i < arr.size();i++)
        {
            out << arr[i] << " ";
        }
        out << "]";
        return out;
    }


}
