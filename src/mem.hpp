
template<class T, int s>
class MemoryClass {
	T* mem;
public:
	MemoryClass();
	T& operator[](unsigned long long index);
};
