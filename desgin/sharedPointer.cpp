#include <iostream>

template<typename T>
class SharedPtr{
    public:
        SharedPtr(T * ptr):sp{ptr},refCnt{new uint32_t{1}}{
            std::cout << "Dafualt\n";
        }
        ~SharedPtr(){
            cleanUp();
        }

        SharedPtr(const SharedPtr<T>& other){
            std::cout << "Copy constructor\n";
            this->sp = other.sp;
            this->refCnt = other.refCnt;
            ++(*this->refCnt);
        }

        SharedPtr& operator=(const SharedPtr<T>& other){
            std::cout << "Copy assignment\n";
            if(&other != this){
                cleanUp();

                this->sp = other.sp;
                this->refCnt = other.refCnt;
                ++(*this->refCnt);
            }
            return *this;
        }

        uint32_t getCount() const{
            return *refCnt;
        }

        T* get() const{
            return sp;
        }

        T* operator->(){
            return sp;
        }

        T& operator*(){
            return *sp;
        }
    private:
        T * sp{nullptr};
        uint32_t * refCnt{nullptr};

        void cleanUp(){
            if(--(*refCnt) == 0){
                std::cout << "Deleting the ref count\n";
                delete refCnt;
                if(sp != nullptr){
                    delete sp;
                    std::cout << "Deleting the raw pointer\n";
                }
            }
        }
};
int main(int argc, char const *argv[])
{
    SharedPtr<int> sp(new int(10));
    std::cout << "Pointer value: " << *sp << " Get count: " << sp.getCount() << "\n";

    SharedPtr<int> sp1 = sp;
    std::cout << "Pointer value: " << *sp1 << " Get count: " << sp1.getCount() << "\n";

    
    SharedPtr<int> sp3(new int(16));
    sp3 = sp1;
    
    std::cout << "Pointer value: " << *sp1 << " Get count: " << sp1.getCount() << "\n";

    return 0;
}
