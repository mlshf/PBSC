#include <iostream>
#include <memory>

class A {
public:

    // ...

    static void* operator new(size_t size) {
        std::cout << "operator new!" << std::endl;
        return ::operator new(size);
    }

    static void operator delete(void* p, size_t size) {
        std::cout << "operator delete!" << std::endl;
        return ::operator delete(p);
    }
};

template < class T >
struct TAllocator_forClass_A {
    typedef T value_type;
    TAllocator_forClass_A() = default;
    template< class U > TAllocator_forClass_A( const TAllocator_forClass_A< U >& ) {};
    T* allocate( std::size_t size ) {
        if( size > std::size_t( -1 ) / sizeof( value_type ) )
            throw std::bad_alloc();
        if( auto p = static_cast< value_type* >( A::operator new( size * sizeof( value_type ) ) ) )
            return p;
        throw std::bad_alloc();
    }
    void deallocate(value_type* p, std::size_t size) {
        A::operator delete( p, size * sizeof(value_type) ); }
};
template <class T, class U>
bool operator==(const TAllocator_forClass_A<T>&, const TAllocator_forClass_A<U>&) { return true; }
template <class T, class U>
bool operator!=(const TAllocator_forClass_A<T>&, const TAllocator_forClass_A<U>&) { return false; }


int main() {
    auto my_allocator = TAllocator_forClass_A<A>();
    auto sp = std::allocate_shared<A>(my_allocator);
}