#ifndef MOVABLE_PTR_HPP
#define MOVABLE_PTR_HPP

template <class T>
class movable_ptr final
{
public:
    movable_ptr(T *ptr = nullptr) : m_ptr(ptr)
    {
    }

    movable_ptr(const movable_ptr &) = delete;

    movable_ptr(movable_ptr &&ptr) noexcept : m_ptr(ptr)
    {
        ptr.m_ptr = nullptr;
    }

    ~movable_ptr() = default;

    T *get()
    {
        return m_ptr;
    }

    const T *get() const
    {
        return m_ptr;
    }

    operator T *()
    {
        return m_ptr;
    }

    operator const T *() const
    {
        return m_ptr;
    }

    T *operator->()
    {
        return m_ptr;
    }

    const T *operator->() const
    {
        return m_ptr;
    }

    movable_ptr &operator=(movable_ptr &&ptr) noexcept
    {
        using std::swap;
        swap(m_ptr, ptr.m_ptr);

        return *this;
    }

private:
    T *m_ptr;

};

#endif
