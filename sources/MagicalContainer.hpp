#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>
#include <algorithm> // for std::sort
#include <cstddef>

namespace ariel{

class MagicalContainer {

private:
    std::vector<int> elements;

    public:
    MagicalContainer() = default; // Default constructor
    MagicalContainer(const MagicalContainer& other) = default; // Copy constructor
    ~MagicalContainer() = default; // Destructor

    std::vector<int>& getElements();
    void setElements(std::vector<int> elements);
    void addElement(int element);
    void removeElement(int element);
    int size() const;


    class AscendingIterator {
        
        private:

            MagicalContainer& container;
            int index;

        public:

            AscendingIterator(const AscendingIterator& copy_container):container(copy_container.container){}//Copy constructor
            ~AscendingIterator() = default; // Destructor

            AscendingIterator(MagicalContainer& container): container(container) {
            std::vector<int> sortedElements = container.getElements();
            std::sort(sortedElements.begin(), sortedElements.end());
            this->container.setElements(sortedElements);
            }

            
            int& operator*() const {
            return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
            }

            AscendingIterator& operator++(){
                this->index = this->index + 1;
                return *this;
            }

            bool operator==(const AscendingIterator& other_iterator) const {
                        return index == other_iterator.index;
            }
            bool operator!=(const AscendingIterator& other_iterator) const {
                        return index != other_iterator.index;
            }
            
            AscendingIterator begin() const{
                    AscendingIterator begin_iterator(container);
                    return begin_iterator;
            }

            
            AscendingIterator end() const{
                AscendingIterator iterator_end(container);
                iterator_end.index = container.size();
                return iterator_end;
            }


        };



    class SideCrossIterator {

    private:
        MagicalContainer& container;
        int index;

    public:
        
        SideCrossIterator(const SideCrossIterator& other_container) : container(other_container.container){} //Copy constructor
        ~SideCrossIterator() = default; //Destructor

        SideCrossIterator(MagicalContainer& container):container(container) {
                std::vector<int> sortedElements = container.getElements();
                std::sort(sortedElements.begin(), sortedElements.end());
                size_t start = 0;
                size_t end = sortedElements.size() -1;
                std::vector<int> crossElements(sortedElements.size());
                for (size_t i = 0; i < crossElements.size() ; i+=2) {
                    crossElements[i] = sortedElements[start];
                    crossElements[i+1] = sortedElements[end];
                    start++;
                    end--;

                }
                this->container.setElements(crossElements);
            }

        int& operator*() const {
            return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
        }
        SideCrossIterator& operator++(){
            // Increment the index
            index++;
            return *this;
        }
       
        bool operator==(const SideCrossIterator& other) const{
            return index == other.index;
        }

        bool operator!=(const SideCrossIterator& other) const{
            return index != other.index;
        }

        bool operator>(const SideCrossIterator& other) const{
            return index > other.index;
        }

        bool operator<(const SideCrossIterator& other) const{
            return index < other.index;
        }

        SideCrossIterator begin() const{
            return SideCrossIterator(container);
        }

        // Return an iterator that point to the end of the container (one past the last element)
        SideCrossIterator end() const{
            SideCrossIterator iterator_end(container);
            iterator_end.index = container.size();
            return iterator_end;
        }


    };

    class PrimeIterator  {

        private:
        
            MagicalContainer& container;
            int index;

        public:
            
            PrimeIterator(const PrimeIterator& other_container) : container(other_container.container){} //Copy constructor
            ~PrimeIterator() = default; //Destructor

            PrimeIterator(MagicalContainer& container):container(container){
                std::vector<int> primeElements;
                for (size_t i = 0; i < container.getElements().size(); i++)
                {
                    if (isPrime(container.getElements()[i])) {
                        primeElements.push_back(container.getElements()[i]);
                    }
                }
                container.setElements(primeElements);
            }

            int& operator*() const {
                return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
            }
             PrimeIterator& operator++(){
                // Increment the index
                index++;
                return *this;
            }
            
            bool operator==(const PrimeIterator& other) const{
                return index == other.index;
            }

            bool operator!=(const PrimeIterator& other) const{
                return index != other.index;
            }

            bool operator>(const PrimeIterator& other) const{
                return index > other.index;
            }

            bool operator<(const PrimeIterator& other) const{
                return index < other.index;
            }

            PrimeIterator begin() const{
                return PrimeIterator(container);
            }

            // Return an iterator that point to the end of the container (one past the last element)
            PrimeIterator end() const{
                PrimeIterator iterator_end(container);
                iterator_end.index = container.size();
                return iterator_end;
            }


            private:
            //help function
            bool isPrime(int number){
                if (number <= 1) {
                return false;
            }
            for (int i = 2; i * i <= number; ++i) {
                if (number % i == 0) {
                    return false;  // Number is divisible, hence not prime
                    }
                }
                return true;
            }
            



        };
    };

}



#endif
