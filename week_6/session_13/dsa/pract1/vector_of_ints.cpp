#include <iostream>
#include <cstdlib>

class Vector{
	private:
		int* p_arr;
		size_t N;
	public:
        Vector() : p_arr(nullptr), N(0) {}
		
		Vector(const size_t init_size) : N(init_size) {
			p_arr = (int*)calloc(N, sizeof(int));
			if (p_arr == NULL){
				std::cout << "Error allcating memory" << std::endl;
				exit(EXIT_FAILURE);
			}
		}

		Vector(const size_t init_size, const int init_val) : N(init_size) {

			p_arr = (int*)malloc(N*sizeof(int));
			if(p_arr == NULL) {
				std::cout << "Error allcating memory" << std::endl;
				exit(EXIT_FAILURE);
			}

			for(int i = 0;  i < N; ++i) {
				p_arr[i] = init_val;
			}
		}

		~Vector() {
			free(p_arr);
		}
		
		int get(const size_t index) const;
		void set(const size_t index, int val);

		void show() const;
		size_t size() const;
		size_t resize(const size_t new_size);
};

int Vector::get(const size_t index) const {
	if (index >= N) {
        std::cerr << "Index out of bounds!" << std::endl;
        exit(EXIT_FAILURE);
    }
	return p_arr[index];
}

void Vector::set(const size_t index, int val) {
	if (index >= N) {
		resize(index+1);
	} else {
		p_arr[index] = val;
	}
}

size_t Vector::size() const {
	return N;
}

size_t Vector::resize(const size_t new_size)
{
	if (new_size > N)
	{
		p_arr = (int *)realloc(p_arr, new_size * sizeof(int));
		if (p_arr == NULL)
		{
			std::cout << "Error:realloc" << std::endl;
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < new_size; ++i)
		{
			p_arr[i] = 0;
		}

		N = new_size;
	}
	return N;
}

void Vector::show() const {
	for(int i=0; i < N; ++i) {
		std::cout << p_arr[i] << " ";
	}
	std::cout << std::endl;
}

void test(void);

int main(void)
{
	test();

	return (0);
}


void test(void)
{
	Vector v1;
	Vector v2(5);
	Vector v3(7, 100);

	v1.set(5, 900);

	std::cout << v1.get(5) << std::endl;	// index bound check
				// return value at index
	
	v1.show();
	v2.show();
	v3.show();

	int m = v1.size();	// return the current size
				// in terms of number of elements
	size_t new_size = 15;
	size_t old_size = v1.resize(new_size);	// new_size ->
						// in terms of number of element
}
