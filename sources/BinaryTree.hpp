#include <iostream>


namespace ariel{


    template<typename T> class BinaryTree{
        private:
            struct Node{
                T _value;
                Node* _left;
                Node* _right;
                Node(T& value, Node* left, Node* right):
                _value(value), _left(left), _right(right){};
            };
            Node* _root;

        public:
            BinaryTree(): _root(nullptr){};
            ~BinaryTree(){};     //?

            class iterator {
                private:
                    Node* curr_node;

                public:
                    iterator(Node* ptr = nullptr): curr_node(ptr) {}

                    T& operator*() const { return curr_node->_value; }

                    T* operator->() const { return &(curr_node->_value); }

                    // ++i;
                    iterator& operator++() {
                        // curr_node = curr_node->m_next;       // next=right or left?
                        return *this;
                    }

                    // i++;
                    const iterator operator++(int) {
                        iterator tmp = *this;
                        // curr_node = curr_node->m_next; // next=right or left?
                        return tmp;
                    }

                    bool operator==(const iterator& other) const {
                        // return curr_node == other.curr_node;
                        return false;
                    }

                    bool operator!=(const iterator& other) const {
                        // return curr_node != other.curr_node;
                        return false;
                    }
            };  // END OF CLASS iterator

            class const_iterator {
                private:
                    Node* curr_node;

                public:
                    const_iterator(Node* ptr = nullptr)
                        : curr_node(ptr) {
                    }
                        
                    const T& operator*() const {
                        return curr_node->_value;
                    }

                    const T* operator->() const {
                        return &(curr_node->_value);
                    }

                    // ++i;
                    const_iterator& operator++() {
                        //++pointer_to_current_node;
                        // curr_node = curr_node->m_next;       //next=?
                        return *this;
                    }

                    // i++;
                    const const_iterator operator++(int) {
                        const_iterator tmp= *this;
                        // curr_node= curr_node->_next;     //next=?
                        return tmp;
                    }

                    bool operator==(const const_iterator& other) const {
                        return curr_node == other.curr_node;
                    }

                    bool operator!=(const const_iterator& other) const {
                        return curr_node != other.curr_node;
                    }
            };  // END OF CLASS const_iterator
            

            iterator begin() { return iterator{_root}; }
            iterator end() { return iterator{nullptr}; }
            const_iterator cbegin() const { return const_iterator{_root}; } 
            const_iterator cend() const { return const_iterator{nullptr}; }


            BinaryTree& add_root(T value) {
                if(_root == nullptr){
                    // Node* root = new Node(value, nullptr, nullptr);
                    _root = new Node(value, nullptr, nullptr);
                }
                else{
                    _root->_value = value;
                }
                return *this;
            }
            
            BinaryTree& add_left(T parent, T left_child) { return *this; }
            BinaryTree& add_right(T parent, T right_child){ return *this; }

            iterator begin_preorder(){ return iterator(_root); }
            iterator end_preorder(){ return iterator(); }
            iterator begin_inorder(){ return iterator(_root); }
            iterator end_inorder(){ return iterator(); }
            iterator begin_postorder(){ return iterator(_root); }
            iterator end_postorder(){ return iterator(); }
            friend std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& b_tree){ return os; }

        // BinaryTree<T>& add_root(T value){ return *this }
        // BinaryTree<T>& add_left(T parent, T left_child){ return *this; }
        // BinaryTree<T>& add_right(T parent, T right_child){ return *this; }
        // BinaryTree<T>::iterator& begin_preorder(){ return iterator(); }
        // BinaryTree<T>::iterator& end_preorder(){ return iterator(); }
        // BinaryTree<T>::iterator& begin_inorder(){ return iterator(); } 
        // BinaryTree<T>::iterator& end_inorder(){ return iterator(); }
        // BinaryTree<T>::iterator& begin_postorder(){ return iterator(); }
        // BinaryTree<T>::iterator& end_postorder(){ return iterator(); }

        // bool BinaryTree<T>::Iterator::hasNext(){}
        // Node* BinaryTree<T>::Iterator::next(){}

        // std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& b_tree){ return os; }

    };

    // template<typename T> BinaryTree<T>& add_root(T value){}
    // template<typename T> BinaryTree<T>& add_left(T parent, T left_child){}
    // template<typename T> BinaryTree<T>& add_right(T parent, T right_child){}
    // template<typename T> BinaryTree<T>::Iterator& begin_preorder(){}
    // template<typename T> BinaryTree<T>::Iterator& end_preorder(){}
    // template<typename T> BinaryTree<T>::Iterator& begin_inorder(){} 
    // template<typename T> BinaryTree<T>::Iterator& end_inorder(){}
    // template<typename T> BinaryTree<T>::Iterator& begin_postorder(){}
    // template<typename T> BinaryTree<T>::Iterator& end_postorder(){}
    // std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& b_tree){}
    //
    //
    // bool BinaryTree<T>::Iterator::hasNext()
    // Node* BinaryTree<T>::Iterator::next()
}