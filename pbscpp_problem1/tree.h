#pragma once

#include <memory>

namespace bintree {
    //enable_shared_from_this нужен, чтобы не создавать shared_ptr из this повторно
    //в replaceLeft и replaceRight, а вместо этого использовать существующий shared_ptr из this.
    template <typename T>
    struct TNode: std::enable_shared_from_this< TNode< T > > {
        using TNodePtr = std::shared_ptr<TNode<T>>;
        using TNodeConstPtr = std::shared_ptr<const TNode<T>>;

        bool hasLeft() const {
            return bool(left);
        }

        bool hasRight() const {
            return bool(right);
        }

        bool hasParent() const {
            return bool(parent);
        }

        T& getValue() {
            return value;
        }

        const T& getValue() const {
            return value;
        }

        TNodePtr getLeft() {
            return left;
        }

        TNodeConstPtr getLeft() const {
            return left;
        }

        TNodePtr getRight() {
            return right;
        }

        TNodeConstPtr getRight() const {
            return right;
        }

        TNodePtr getParent() {
            //Т.к. parent - weak_ptr, то используем lock для преобразования к shared_ptr
            return parent.lock();
        }

        TNodeConstPtr getParent() const {
            //аналогично getParent выше.
            return parent.lock();
        }

        static TNodePtr createLeaf(T v) {
            //Чтобы осуществить вызов приватного конструктора, пришлось отнаследоваться от TNode.
            //Результат неявно преобразуется к TNodePtr.
            struct TCheatNode: public TNode{
                TCheatNode( T v ): TNode( v ) {}
            };
            return std::make_shared<TCheatNode>(v);
        }

        static TNodePtr fork(T v, TNodePtr left, TNodePtr right ) {
            //аналогично createLeaf
            struct TCheatNode: public TNode{
                TCheatNode( T v, TNodePtr left, TNodePtr right ): TNode( v, left, right ) {}
            };
            TNodePtr ptr = std::make_shared<TCheatNode>(v, left, right);
            setParent(ptr->getLeft(), ptr);
            setParent(ptr->getRight(), ptr);
            return ptr;
        }

        TNodePtr replaceLeft(TNodePtr l) {
            //TNodePtr( this ) в setParent создавал новый shared_ptr на объект,
            //вместо этого используем уже существующий указатель.
            //Т.о. избежим повторного создания указателя.
            setParent(l, this->shared_from_this());
            setParent(left, nullptr);
            std::swap(l, left);
            return l;
        }

        TNodePtr replaceRight(TNodePtr r) {
            //аналогично replaceLeft
            setParent(r, this->shared_from_this());
            setParent(right, nullptr);
            std::swap(r, right);
            return r;
        }

        TNodePtr replaceRightWithLeaf(T v) {
            return replaceRight(createLeaf(v));
        }

        TNodePtr replaceLeftWithLeaf(T v) {
            return replaceLeft(createLeaf(v));
        }

        TNodePtr removeLeft() {
            return replaceLeft(nullptr);
        }
        TNodePtr removeRight() {
            return replaceRight(nullptr);
        }

    private:
        T value;
        TNodePtr left = nullptr;
        TNodePtr right = nullptr;
        //Нужно, чтобы не было циклической зависимости.
        std::weak_ptr< TNode< T > > parent;

        TNode(T v)
                : value(v)
        {
        }
        //Во избежание дублирования shared_ptr, в качестве аргументов используется shared_ptr
        //вместо raw ptr.
        TNode(T v, TNodePtr left, TNodePtr right)
                : value(v)
                , left(left)
                , right(right)
        {
        }

        static void setParent(TNodePtr node, TNodePtr parent) {
            if (node)
                node->parent = parent;
        }
    };
}