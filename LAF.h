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

        constexpr T& at(int idx)
        {
            
        }
        constexpr const T& at(int idx) const
        {
            
        }

        constexpr T& front()
        {
            
        }
        constexpr const T& front() const
        {
            
        }

        constexpr T& back()
        {
            
        }
        constexpr const T& back() const
        {
            
        }

        constexpr T* data() noexcept
        {

        }
        constexpr const T* data() const noexcept
        {
            
        }

        //lots of const ite

        constexpr const T* begin() const noexcept
        {

        }

        constexpr const T* cbegin() const noexcept
        {

        }

        constexpr const T* end() const noexcept
        {

        }

        constexpr const T* cend() const noexcept
        {

        }

        //reverse iterators, 

        constexpr T* rbegin()
        {
            
        }

        constexpr const T* rbegin() const noexcept
        {

        }

        constexpr const T* crbegin() const noexcept
        {

        }

        constexpr T* rend()
        {
            
        }

        constexpr const T* rend() const noexcept
        {

        }

        constexpr const T* crend() const noexcept
        {

        }

        constexpr bool empty() const noexcept 
        {
            return false;
        }

        constexpr T* insert(const T* pos, const T& value)
        {

        }

        constexpr T* insert(const T* pos, T&& value)
        {

        }

        constexpr T* insert(const T* pos, int cnt, const T& value)
        {

        }

        template<class it>
        constexpr T* insert(const T* pos, it beg, it end)
        {

        }

        constexpr T* insert(const T* pos, std::initializer_list<T> ls)
        {

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

        constexpr Vector(int cnt, const T& val)
        {

        }

        constexpr Vector(int cnt)
        {

        }

        //copy
        constexpr Vector(const Vector& other)
        {

        }

        //move
        constexpr Vector(Vector&& other)
        {

        }

        constexpr Vector& operator=(const Vector& other)
        {
            
        }

        constexpr Vector& operator=(Vector&& other)
        {
                    
        }

        constexpr Vector& operator=(std::initializer_list<T> ls)
        {
                
        }

        constexpr void assign(int cnt, const T& val)
        {

        }

        template<class it>
        constexpr void assign(it beg, it en)
        {

        }

        constexpr void assign(std::initializer_list<T> ls)
        {
            
        }

        template< class... Args >
        constexpr T* emplace(const T* pos, Args&&... args)
        {

        }

        constexpr T* erase(const T* pos)
        {

        }

        constexpr T* erase(const T* beg, const T* end)
        {

        }

        constexpr void pop_back()
        {

        }

        constexpr void resize(int count)
        {

        }

        constexpr void resize(int count, const T& value)
        {

        }

        constexpr void swap(Vector& other) noexcept
        {

        }

        constexpr void fake_clear()
        {
            _last_ptr = 0;
        }

        //clear() reset the internal size, which is incorrect according to std::vector 
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

        constexpr void push_back(T &&value)
        {

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

template<class T>
constexpr void swap(LAF::Vector<T>& lhs, LAF::Vector<T>& rhs)
{

}

template<class T>
constexpr bool operator==(const LAF::Vector<T>& lhs, const LAF::Vector<T>& rhs)
{
    return false;
}

template<class T>
bool operator<(const LAF::Vector<T>& lhs, const LAF::Vector<T>& rhs)
{
    
}

template<class T>
bool operator>(const LAF::Vector<T>& lhs, const LAF::Vector<T>& rhs)
{
    
}

template<class T>
bool operator>=(const LAF::Vector<T>& lhs, const LAF::Vector<T>& rhs)
{
    
}

template<class T>
bool operator<=(const LAF::Vector<T>& lhs, const LAF::Vector<T>& rhs)
{
    
}

template<class T>
bool operator!=(const LAF::Vector<T>& lhs, const LAF::Vector<T>& rhs)
{
    
}
