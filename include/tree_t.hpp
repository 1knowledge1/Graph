#include <iostream>
template <class T>
class tree_t
{
private:
	struct node_t {
		node_t * left;
		node_t * right;
		T value;

		node_t() {
			left = nullptr;
			right = nullptr;
			value = 0;
		}
		~node_t() {
			delete left;
			delete right;
		}
		void add(T val) {
			if (value > val) {
				if (!left) {
					left = new node_t();
					left->value = val;
				}
				else left->add(val);
			}
			else if (value < val) {
				if (!right) {
					right = new node_t();
					right->value = val;
				}
				else right->add(val);
			}
			return;
		}
		bool find_t(T val) const {
			if (value == val) {
				return true;
			}
			if (value > val) {
				if (left) {
					return left->find_t(val);
				}
				else return false;
			}
			if (value < val) {
				if (right) {
					return right->find_t(val);
				}
				else return false;
			}
		}
		void print_t(std::ostream & stream, int num = 0) const {
			if (right) {
				right->print_t(stream, num + 4);
			}
			for (int i = 0; i < num + 4; i++) {
				stream << '-';
			}
			stream << value << '\n';
			if (left) {
				left->print_t(stream, num + 4);
			}
			return;
		}
		bool compare(node_t const * other) const {
			bool res = true;
			if ((!left && !other->left) || (left && other->left)) {
				if (left && other->left) {
					if (left->value == other->left->value) { 
						if (!left->compare(other->left)) res = false; 
					}
					else return false;
				}
			}
			else return false;

			if ((!right && !other->right) || (right && other->right)) {
				if (right && other->right) {
					if (right->value == other->right->value) { 
						if (!right->compare(other->right)) res = false; 
					}
					else return false;
				}
			}
			else return false;
			return res;
		}
	};
private:
	node_t * root_;
public:
	tree_t() {
		root_ = nullptr;
	}
	~tree_t() {
		delete root_;
	}
	
	//bool remove(T key);
	tree_t(std::initializer_list<T> keys) {
		root_ = nullptr;
		for (T i : keys) {
			this->insert(i);
		}
	}
	auto operator==(tree_t const & other) const {
		if (!root_ && !other.root_) return true;
		if (root_ && other.root_) {
			if (root_->value == other.root_->value) {
				return root_->compare(other.root_);
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	void insert(T value) {
		if (!root_) {
			root_ = new node_t;
			root_->value = value;
			return;
		}
		else {
			root_->add(value);
			return;
		}
	}
	bool find(T value) const {
		if (root_) {
			return root_->find_t(value);
		}
		return false;
	}
	void print(std::ostream & stream) const {
		if (root_) {
			root_->print_t(stream, 0);
		}
		else std::cout << "Tree is empty\n";
		return;
	}
};
