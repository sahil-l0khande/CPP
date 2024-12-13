#include <iostream>
#include <cstdlib>

class vector {
	private:
		int* p_arr;
		size_t N;
	public:
		vector() : p_arr(nullptr), N(0) {}

		vector(const size_t init_size) : N(init_size) {
			p_arr = (int*)calloc(N, sizeof(int));
			if(p_arr == NULL) {
				std::cout << "Error, calloc()" << std::endl;
				exit(EXIT_FAILURE);
			}
		}

		vector(const size_t init_size, const int init_val): N(init_size) {
			p_arr = (int*) malloc(N*sizeof(int));
			if(p_arr == NULL) {
				std::cout << "Error allocating memory" << std::endl;
				exit(EXIT_FAILURE);
			}

			for(int i = 0; i < N; ++i) {
				p_arr[i] = init_val;
			}
		}

		~vector() {
			free(p_arr);
		}

		int get(const size_t index) const {
			if (index >= N) {
				std::cout << "Index out of bound" << std::endl;
				exit(EXIT_FAILURE);
			}

			return p_arr[index];
		}

		void set(const size_t index, int val) {
			if (index >= N) {
				resize(index+1);
			} else {
				p_arr[index] = val;
			}
		}

		void show() const {
			for(int i = 0; i < N; ++i) {
				std::cout << p_arr[i] << " ";
			}

			std::cout << std::endl;
		}

		size_t size() const {
			return N;
		}

		size_t resize(const size_t new_size) {
			p_arr = (int*)realloc(p_arr, new_size*sizeof(int));
			if(p_arr == NULL) {
				std::cout << "Error:realloc" << std::endl;
				exit(EXIT_FAILURE);
			}

			for(int i = 0; i < new_size; ++i)
				p_arr[i] = 0;

			N = new_size;

			return N;
		}

};

void test(void)
{
	vector v1;
	vector v2(5);
	vector v3(7,1000);

	v1.set(0, 200);

	std::cout<<v1.get(0) << std::endl;

	v1.show();
	v2.show();
	v3.show();

	std::cout << "Size of v1 is " << v1.size() << std::endl;
	std::cout << "Prev Size of v1 was " << v1.resize(10) << std::endl;
}

int main(void) {
	test();
	return (0);
}
